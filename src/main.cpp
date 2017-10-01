#include <iostream>
#include "simplewav/Wav.hpp"

using namespace std;

int main() {
//  try {
    Wav wav1;
    wav1.loadFromFile("chornye-glaza.wav");
    cout << wav1.getDescription() << endl;
    wav1.convertStereoToMono();
    wav1.applyReverb(0.500, 0.6f);
    wav1.saveToFile("black-eyes-mono.wav");

    Wav wav2("secret-speech.wav");
    cout << wav2.getDescription() << endl;
    int sampleRate = wav2.getSampleRate();
    int chanCount = wav2.getChanCount();
    bool isStereo = wav2.isStereo();

    wav2.changeSampleRate(22050);

    // Cut first 10 seconds and last 20 seconds
    wav2.cutBegin(10.0);
    wav2.cutEnd(20.0);

    wav2.save(); // Overwrite the original file.

//  } catch (WavError& we) {
//    cerr << we.what();
//  }
  return 0;
}