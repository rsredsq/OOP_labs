#include <fstream>

#include "WavWriter.hpp"

namespace SimpleWav {
  void WavWriter::save(const std::string& filePath, Wav& wav) {
    std::ofstream fileContent(filePath, std::ios_base::out | std::ios_base::binary);

    WavWriter writer(fileContent, wav.header());
    writer.saveWavFile();
  }

  WavWriter::WavWriter(std::ostream& contentStream, const WavHeader& wav)
      : contentStream(contentStream),
        wav(wav) {
  }

  void WavWriter::saveWavFile() {
    saveWavHeader();
    saveWavData();
  }

  void WavWriter::saveWavHeader() {
    saveRifChunk();
    saveFmtChunk();
    saveDataHeader();
  }

#define writeToContentStream(value) (contentStream.write((value).data(), sizeof(value)))

  void WavWriter::saveRifChunk() {
    auto& chunk = wav.rifChunk;
    writeToContentStream(chunk.chunkId);
    writeToContentStream(chunk.chunkSize);
    writeToContentStream(chunk.format);
  }

  void WavWriter::saveFmtChunk() {
    auto& chunk = wav.fmtChunk;
    writeToContentStream(chunk.subChunk1Id);
    writeToContentStream(chunk.subChunk1Size);
    writeToContentStream(chunk.audioFormat);
    writeToContentStream(chunk.numChannels);
    writeToContentStream(chunk.sampleRate);
    writeToContentStream(chunk.byteRate);
    writeToContentStream(chunk.blockAlign);
    writeToContentStream(chunk.bitsPerSample);
  }

  void WavWriter::saveDataHeader() {
    auto& header = wav.dataHeader;
    writeToContentStream(header.subChunk2Id);
    writeToContentStream(header.subChunk2Size);
  }

  void WavWriter::saveWavData() {
    auto dataBegin = wav.dataHeader.data.begin();
    auto dataEnd = wav.dataHeader.data.end();
    auto outIterator = std::ostreambuf_iterator<char>(contentStream);

    std::copy(dataBegin, dataEnd, outIterator);
  }
}