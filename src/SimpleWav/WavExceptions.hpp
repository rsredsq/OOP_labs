#pragma once

#include <exception>

class IOException : public std::runtime_error {
public:
  explicit IOException(const std::string& fileName) : std::runtime_error("IO exception: " + fileName) {

  }
};

class RIFHeaderCorruptedException : public std::runtime_error {
public:
  explicit RIFHeaderCorruptedException() : std::runtime_error("RIFHeaderCorruptedException") {

  }
};

class FMTHeaderCorruptedException : public std::runtime_error {
public:
  explicit FMTHeaderCorruptedException() : std::runtime_error("FMTHeaderCorruptedException") {

  }
};

class DATAHeaderCorruptedException : public std::runtime_error {
public:
  explicit DATAHeaderCorruptedException() : std::runtime_error("DATAHeaderCorruptedException") {

  }
};
