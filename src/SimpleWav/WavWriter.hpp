#pragma once

#include "Wav.hpp"

namespace SimpleWav {
  class WavWriter {
  public:
    WavWriter() = delete;
    explicit WavWriter(std::ostream& contentStream, const WavHeader& wav);
    static void save(const std::string& filePath, Wav& wav);
  private:
    void saveWavFile();
    void saveWavHeader();
    void saveWavData();
    void saveFmtChunk();
    void saveRifChunk();
    void saveDataHeader();

    std::ostream& contentStream;
    const WavHeader& wav;
  };
}


