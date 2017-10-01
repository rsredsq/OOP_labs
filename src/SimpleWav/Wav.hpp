#pragma once


#include <string>

class Wav {
public:
  explicit Wav(const std::string& filePath);


  void convertStereoToMono();

  void applyReverbation(double delay, double decay);

  void changeSampleRate(int newSampleRate);

  void cutBegin(double timeBegin);

  void cutEnd(double timeEnd);

  void save();

  bool isStereo();

  const std::string& getDescription() {
    return description;
  }

  int getSampleRate() {
    return sampleRate;
  };

  int getChanCount() {
    return channelsCount;
  };

private:
  std::string description;
  int channelsCount;
  int sampleRate;
};


