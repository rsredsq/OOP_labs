#pragma once

#include <cstdint>
#include <boost/endian/arithmetic.hpp>

namespace SimpleWav {
  struct RIFChunk {
    boost::endian::big_int8_t chunkId[4];
    boost::endian::little_int32_t chunkSize;
    boost::endian::big_int8_t format[4];
  };

  struct FMTChunk {
    boost::endian::big_int8_t subChunk1Id[4];
    boost::endian::little_uint32_t subChunk1Size;
    boost::endian::little_uint16_t audioFormat;
    boost::endian::little_uint16_t numChannels;
    boost::endian::little_uint32_t sampleRate;
    boost::endian::little_uint32_t byteRate;
    boost::endian::little_uint16_t blockAlign;
    boost::endian::little_uint16_t bitsPerSample;
  };

  struct DATAHeader {
    boost::endian::big_int8_t subChunk2Id[4];
    boost::endian::little_int32_t subChunk2Size;
  };

  struct WAVHeader {
    RIFChunk rifChunk;
    FMTChunk fmtChunk;
    DATAHeader dataHeader;
  };
}
