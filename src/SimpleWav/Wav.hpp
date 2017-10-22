#pragma once

#include <string>
#include <memory>
#include <vector>
#include "WavHeader.hpp"

namespace SimpleWav {

  class Wav {
    friend class WavReader;

  public:

    void convertStereoToMono();

    void applyReverbation(double delay, double decay);

    void changeSampleRate(int newSampleRate);

    void cutBegin(const std::chrono::milliseconds timeBegin);

    void cutEnd(const std::chrono::milliseconds timeEnd);

    void save() const;

    bool isStereo() const;

    WavDataContainer& data() {
      return header.dataHeader.data;
    }

    const std::string getDescription() const;

    int getSampleRate() const;

    int getChannelsCount() const;

  private:
    explicit Wav() = default;
    WAVHeader header;

    void updateWavHeader();
    void updateRifHeader();
    void updateFmtHeader();
    void updateDataHeader();
    void verifyHeader();

    long bytesInMs(const std::chrono::milliseconds ms) {
      return (header.fmtChunk.bitsPerSample / 8) * header.fmtChunk.sampleRate * ms.count();
    }

  };
}