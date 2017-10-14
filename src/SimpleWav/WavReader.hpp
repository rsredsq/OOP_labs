#pragma once

#include <istream>
#include <boost/endian/arithmetic.hpp>
#include "Wav.hpp"

namespace SimpleWav {
  class WavReader {
  public:
    WavReader() = delete;
    explicit WavReader(std::istream& contentStream);
    static Wav ResolveFromFile(const std::string& filePath);
  private:
    Wav parseWavFile();
    WAVHeader readWavHeader();
    WavDataContainer readWavData();
    FMTChunk readFmtChunk();
    RIFChunk readRifChunk();
    DATAHeader readDataHeader();

    std::istream& contentStream;
  };
}


