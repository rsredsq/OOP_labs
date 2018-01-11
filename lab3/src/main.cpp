#include <iostream>
#include "SimpleWav/Wav.hpp"
#include "SimpleWav/WavReader.hpp"
#include "SimpleWav/WavExceptions.hpp"
#include "SimpleWav/WavWriter.hpp"

using namespace std;
using namespace SimpleWav;

int main() {


  auto parsedWav = WavReader::ResolveFromFile("res/0.wav");

  cout << parsedWav.getDescription();

  parsedWav.cutBegin(10s);

  WavWriter::save("res/out.wav", parsedWav);
  return 0;
}