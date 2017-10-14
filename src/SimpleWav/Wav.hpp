#pragma once

#include <string>
#include <memory>
#include <vector>
#include "WavHeader.hpp"

namespace SimpleWav {
  using WavDataContainer = std::vector<boost::endian::little_int8_t>;

  class Wav {
    friend class WavReader;

  public:

    void convertStereoToMono();

    void applyReverbation(double delay, double decay);

    void changeSampleRate(int newSampleRate);

    void cutBegin(double timeBegin);

    void cutEnd(double timeEnd);

    void save() const;

    bool isStereo() const;

    const std::string& getDescription() const;

    int getSampleRate() const;

    int getChannelsCount() const;

  private:
    explicit Wav() = default;
    WAVHeader header;
    WavDataContainer data;
  };
}