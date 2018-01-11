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

    void cutBegin(std::chrono::seconds timeBegin);

    void cutEnd(std::chrono::seconds timeEnd);

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
    long bytesInSec(std::chrono::seconds ms);
  };
}