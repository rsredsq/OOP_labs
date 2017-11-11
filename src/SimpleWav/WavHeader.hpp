#pragma once

#include <boost/endian/arithmetic.hpp>
#include "WavExceptions.hpp"

namespace SimpleWav {

  using WavDataContainer = std::vector<char>;

  const boost::endian::big_int32_t RIF_CHUNK_ID = 0x52494646;
  const boost::endian::big_int32_t WAVE_FORMAT_HEX = 0x57415645;
  const boost::endian::big_int32_t FMT_CHUNK_ID = 0x666d7420;
  const boost::endian::little_int32_t PCM_CHUNK_SIZE = 16;
  const boost::endian::little_int32_t PCM_AUDIO_FORMAT = 1;
  const boost::endian::big_int32_t DATA_CHUNK_ID = 0x64617461;

  constexpr int BYTE_SIZE = 8;

  struct RIFChunk {
    boost::endian::big_int32_t chunkId;
    boost::endian::little_int32_t chunkSize;
    boost::endian::big_int32_t format;
  };

  struct FMTChunk {
    boost::endian::big_int32_t subChunk1Id;
    boost::endian::little_uint32_t subChunk1Size;
    boost::endian::little_uint16_t audioFormat;
    boost::endian::little_uint16_t numChannels;
    boost::endian::little_uint32_t sampleRate;
    boost::endian::little_uint32_t byteRate;
    boost::endian::little_uint16_t blockAlign;
    boost::endian::little_uint16_t bitsPerSample;
  };

  struct DATAHeader {
    boost::endian::big_int32_t subChunk2Id;
    boost::endian::little_int32_t subChunk2Size;
    WavDataContainer data;
  };

  struct WAVHeader {
    RIFChunk rifChunk;
    FMTChunk fmtChunk;
    DATAHeader dataHeader;

    void verify() {
      verifyRifHeader();
      verifyFmtHeader();
      verifyDataHeader();
    }
  private:
    void verifyRifHeader() {
      bool chunkIdCorrect = rifChunk.chunkId == RIF_CHUNK_ID;

      bool chunkSizeCorrect = rifChunk.chunkSize ==
                              (4 + (BYTE_SIZE + fmtChunk.subChunk1Size) +
                               (BYTE_SIZE + dataHeader.subChunk2Size));

      bool formatCorrect = rifChunk.format == WAVE_FORMAT_HEX;

      if (not(chunkIdCorrect && chunkSizeCorrect && formatCorrect)) {
        throw RIFHeaderCorruptedException();
      }
    }

    void verifyFmtHeader() {
      bool chunkIdCorrect = fmtChunk.subChunk1Id == FMT_CHUNK_ID;
      bool chunkSizeCorrect = fmtChunk.subChunk1Size == PCM_CHUNK_SIZE;
      bool audioFormatSupported = fmtChunk.audioFormat == PCM_AUDIO_FORMAT;

      bool byteRateCorrect = fmtChunk.byteRate ==
                             fmtChunk.sampleRate *
                             fmtChunk.numChannels *
                             (fmtChunk.bitsPerSample / BYTE_SIZE);

      bool blockAligned = fmtChunk.blockAlign ==
                          fmtChunk.numChannels * (fmtChunk.bitsPerSample / BYTE_SIZE);

      if (not(chunkIdCorrect && chunkSizeCorrect && audioFormatSupported && byteRateCorrect && blockAligned)) {
        throw FMTHeaderCorruptedException();
      }
    }

    void verifyDataHeader() {
      bool chunkIdCorrect = dataHeader.subChunk2Id == DATA_CHUNK_ID;
      bool chunkSizeCorrect = dataHeader.subChunk2Size == dataHeader.data.size();

      if (not(chunkIdCorrect && chunkSizeCorrect)) {
        throw DATAHeaderCorruptedException();
      }
    }
  };
}
