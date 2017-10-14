#include <iostream>
#include <fstream>
#include "SimpleWav/Wav.hpp"
#include "SimpleWav/WavHeader.hpp"
#include "SimpleWav/WavReader.hpp"
#include <functional>

using namespace std;
using namespace SimpleWav;

int main() {


//  auto parsedWav = WavReader::ResolveFromFile("res/0.wav");


//  cout << parsedWav.header.rifChunk.chunkId->data();
//  cout << parsedWav.header.rifChunk.format;
//
//  cout << parsedWav.header.fmtChunk.subChunk1Id;


//  WAVHeader header {};
//  cout << sizeof(header);
//  ifstream stream("res/0.wav");
//
//  stream.read(header.rifChunk.chunkSize, 4);
//  stream.read(header.rifChunk.chunkId, 8);
//  stream.read(header.rifChunk.format, 16);


//  stream >> header.rifChunk.chunkSize[4];
//  stream >> test[5];
//  stream >> test[6];

//  cout << header.rifChunk.chunkSize;
//  cout << header.rifChunk.chunkId;
//  cout << header.rifChunk.format;

//  stream >> header.rifChunk;
//
//  cout << header.rifChunk.chunkId << endl;
//  cout << header.rifChunk.chunkSize << endl;
//  cout << header.rifChunk.format << endl;

//  try {
//    Wav wav1;
//    wav1.loadFromFile("chornye-glaza.wav");
//    cout << wav1.getDescription() << endl;
//    wav1.convertStereoToMono();
//    wav1.applyReverb(0.500, 0.6f);
//    wav1.saveToFile("black-eyes-mono.wav");
//
//    Wav wav2("secret-speech.wav");
//    cout << wav2.getDescription() << endl;
//    int sampleRate = wav2.getSampleRate();
//    int chanCount = wav2.getChannelsCount();
//    bool isStereo = wav2.isStereo();
//
//    wav2.changeSampleRate(22050);
//
//    // Cut first 10 seconds and last 20 seconds
//    wav2.cutBegin(10.0);
//    wav2.cutEnd(20.0);
//
//    wav2.save(); // Overwrite the original file.

//  } catch (WavError& we) {
//    cerr << we.what();
//  }
  return 0;
}