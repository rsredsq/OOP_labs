#include <sstream>
#include "Wav.hpp"

namespace SimpleWav {

  void Wav::convertStereoToMono() {
    //TODO
  }

  void Wav::applyReverberation(double delay, double decay) {
    //TODO
  }

  bool Wav::isStereo() const {
    return wavHeader.fmtChunk.numChannels == 2;
  }

  void Wav::changeSampleRate(int newSampleRate) {
    //TODO
  }

  void Wav::cutBegin(const std::chrono::seconds timeBegin) {
    using namespace std::chrono;
    long bytesToDelete = bytesInSec(timeBegin);
    data().erase(data().begin(), data().begin() + bytesToDelete);
    updateHeader();
  }

  void Wav::cutEnd(const std::chrono::seconds timeEnd) {
    using namespace std::chrono;
    long bytesToDelete = bytesInSec(timeEnd);
    data().erase(data().end() - bytesToDelete, data().end());
    updateHeader();
  }

  void Wav::updateHeader() {
    updateDataHeader();
    updateFmtHeader();
    updateRifHeader();
    verifyHeader();
  }

  void Wav::updateRifHeader() {
    wavHeader.rifChunk.chunkSize = (4 + (BYTE_SIZE + wavHeader.fmtChunk.subChunk1Size) +
                                 (BYTE_SIZE + wavHeader.dataHeader.subChunk2Size));
  }

  void Wav::updateFmtHeader() {
  }

  void Wav::updateDataHeader() {
    wavHeader.dataHeader.subChunk2Size = data().size();
  }

  void Wav::verifyHeader() {
    wavHeader.verify();
  }

  int Wav::getSampleRate() const {
    return wavHeader.fmtChunk.sampleRate;
  }

  int Wav::getChannelsCount() const {
    return wavHeader.fmtChunk.numChannels;
  }

  WavDataContainer& Wav::data() {
    return wavHeader.dataHeader.data;
  }

  WavHeader& Wav::header() {
    return wavHeader;
  }

  long Wav::bytesInSec(std::chrono::seconds sec) {
    return (wavHeader.fmtChunk.bitsPerSample / BYTE_SIZE) * wavHeader.fmtChunk.sampleRate * sec.count();
  }

#define writeHeaderData(stream, value) (stream) << #value " = "; \
                            (stream) << wavHeader.value; \
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