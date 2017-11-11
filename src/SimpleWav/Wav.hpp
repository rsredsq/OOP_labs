#pragma once

#include <string>
#include <memory>
#include <vector>
#include <chrono>
#include "WavHeader.hpp"

namespace SimpleWav {

  class Wav {
    friend class WavReader;

  public:

    void convertStereoToMono();

    void applyReverberation(double delay, double decay);

    void changeSampleRate(int newSampleRate);

    void cutBegin(std::chrono::milliseconds timeBegin);

    void cutEnd(std::chrono::milliseconds timeEnd);

    bool isStereo() const;

    WavHeader& header();

    WavDataContainer& data();

    const std::string getDescription() const;

    int getSampleRate() const;

    int getChannelsCount() const;

  private:
    explicit Wav() = default;
    WavHeader wavHeader;

    void updateHeader();
    void updateRifHeader();
    void updateFmtHeader();
    void updateDataHeader();
    void verifyHeader();
    long bytesInMs(std::chrono::milliseconds ms);
  };
}