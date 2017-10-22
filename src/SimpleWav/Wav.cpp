#include <sstream>
#include "Wav.hpp"

namespace SimpleWav {

  void Wav::convertStereoToMono() {

  }

  void Wav::applyReverbation(double delay, double decay) {

  }


  bool Wav::isStereo() const {
    return false;
  }

  void Wav::changeSampleRate(int newSampleRate) {

  }

  void Wav::save() const {

  }

  void Wav::cutBegin(const std::chrono::milliseconds timeBegin) {
    using namespace std::chrono;
    long bytesToDelete = bytesInMs(milliseconds(timeBegin));
    data().erase(data().begin(), data().begin() + bytesToDelete);
    updateWavHeader();
  }

  void Wav::cutEnd(const std::chrono::milliseconds timeEnd) {
    using namespace std::chrono;
    long bytesToDelete = bytesInMs(milliseconds(timeEnd));
    data().erase(data().end() - bytesToDelete, data().end());
    updateWavHeader();
  }

  void Wav::updateWavHeader() {
//    updateRifHeader();
//    updateFmtHeader();
//    updateDataHeader();
  }

  void Wav::updateRifHeader() {

  }

  void Wav::verifyHeader() {
    header.verify();
  }

#define writeHeaderData(stream, value) (stream) << #value " = "; \
                            (stream) << header.value; \
                            (stream) << "\n";

  const std::string Wav::getDescription() const {
    std::ostringstream stream;

    writeHeaderData(stream, rifChunk.chunkId);
    writeHeaderData(stream, rifChunk.chunkSize);
    writeHeaderData(stream, rifChunk.format);

    writeHeaderData(stream, fmtChunk.subChunk1Id);
    writeHeaderData(stream, fmtChunk.subChunk1Size);
    writeHeaderData(stream, fmtChunk.audioFormat);
    writeHeaderData(stream, fmtChunk.numChannels);
    writeHeaderData(stream, fmtChunk.sampleRate);
    writeHeaderData(stream, fmtChunk.byteRate);
    writeHeaderData(stream, fmtChunk.blockAlign);
    writeHeaderData(stream, fmtChunk.bitsPerSample);

    writeHeaderData(stream, dataHeader.subChunk2Id);
    writeHeaderData(stream, dataHeader.subChunk2Size);

    return stream.str();
  }
}