#include <fstream>
#include <iostream>
#include "WavReader.hpp"

namespace SimpleWav {

  Wav WavReader::ResolveFromFile(const std::string& filePath) {
    std::ifstream fileContent(filePath, std::ios::binary);
    if (not fileContent.is_open()) throw IOException(filePath);
    WavReader reader(fileContent);
    return reader.parseWavFile();
  }

  WavReader::WavReader(std::istream& contentStream)
      : contentStream(contentStream) {
  }

  Wav WavReader::parseWavFile() {
    Wav wav{};
    wav.wavHeader = readWavHeader();
    wav.wavHeader.dataHeader.data = readWavData();
    wav.verifyHeader();
    return std::move(wav);
  }

  WavHeader WavReader::readWavHeader() {
    WavHeader header{};

    header.rifChunk = readRifChunk();
    header.fmtChunk = readFmtChunk();
    header.dataHeader = readDataHeader();

    return header;
  }

  WavDataContainer WavReader::readWavData() {
    auto dataBegin = std::istreambuf_iterator<char>(contentStream);
    auto dataEnd = std::istreambuf_iterator<char>();

    return WavDataContainer(dataBegin, dataEnd);
  }

#define readFromContentStream(value) (contentStream.read(reinterpret_cast<char*>(&(value)), sizeof(value)))

  RIFChunk WavReader::readRifChunk() {
    RIFChunk chunk{};

    readFromContentStream(chunk.chunkId);
    readFromContentStream(chunk.chunkSize);
    readFromContentStream(chunk.format);

    return chunk;
  }

  FMTChunk WavReader::readFmtChunk() {
    FMTChunk chunk{};

    readFromContentStream(chunk.subChunk1Id);
    readFromContentStream(chunk.subChunk1Size);
    readFromContentStream(chunk.audioFormat);
    readFromContentStream(chunk.numChannels);
    readFromContentStream(chunk.sampleRate);
    readFromContentStream(chunk.byteRate);
    readFromContentStream(chunk.blockAlign);
    readFromContentStream(chunk.bitsPerSample);

    return chunk;
  }

  DATAHeader WavReader::readDataHeader() {
    DATAHeader header{};

    readFromContentStream(header.subChunk2Id);
    readFromContentStream(header.subChunk2Size);

    return header;
  }

}
