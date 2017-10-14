#include <fstream>
#include <iostream>
#include "WavReader.hpp"

namespace SimpleWav {

  Wav WavReader::ResolveFromFile(const std::string& filePath) {
    std::ifstream fileContent(filePath);
    if (fileContent.bad()) throw "PIZDA";
    WavReader reader(fileContent);
    return reader.parseWavFile();
  }

  WavReader::WavReader(std::istream& contentStream)
      : contentStream(contentStream) {
  }

  Wav WavReader::parseWavFile() {
    Wav wav{};
    wav.header = readWavHeader();
    wav.data = readWavData();
    return std::move(wav);
  }

  WAVHeader WavReader::readWavHeader() {
    WAVHeader header{};

    header.rifChunk = readRifChunk();
    header.fmtChunk = readFmtChunk();
    header.dataHeader = readDataHeader();

    return header;
  }

  WavDataContainer WavReader::readWavData() {
    auto container = WavDataContainer();
    auto dataBegin = std::istream_iterator<boost::endian::little_uint8_t>(contentStream);
    auto dataEnd = std::istream_iterator<boost::endian::little_uint8_t>();

    container.insert(container.begin(), dataBegin, dataEnd);
    return std::move(container);
  }

#define readFromContentStream(value, size) (contentStream.read(reinterpret_cast<char*>(&(value)), size))

  RIFChunk WavReader::readRifChunk() {
    RIFChunk chunk{};

    readFromContentStream(chunk.chunkId, sizeof(chunk.chunkId));
    readFromContentStream(chunk.chunkSize, sizeof(chunk.chunkSize));
    readFromContentStream(chunk.format, sizeof(chunk.format));

    return chunk;
  }

  FMTChunk WavReader::readFmtChunk() {
    FMTChunk chunk{};

    readFromContentStream(chunk.subChunk1Id, sizeof(chunk.subChunk1Id));
    readFromContentStream(chunk.subChunk1Size, sizeof(chunk.subChunk1Size));
    readFromContentStream(chunk.audioFormat, sizeof(chunk.audioFormat));
    readFromContentStream(chunk.numChannels, sizeof(chunk.numChannels));
    readFromContentStream(chunk.sampleRate, sizeof(chunk.sampleRate));
    readFromContentStream(chunk.byteRate, sizeof(chunk.byteRate));
    readFromContentStream(chunk.blockAlign, sizeof(chunk.blockAlign));
    readFromContentStream(chunk.bitsPerSample, sizeof(chunk.bitsPerSample));

    return chunk;
  }

  DATAHeader WavReader::readDataHeader() {
    DATAHeader header{};

    readFromContentStream(header.subChunk2Id, sizeof(header.subChunk2Id));
    readFromContentStream(header.subChunk2Size, sizeof(header.subChunk2Size));

    return header;
  }

}
