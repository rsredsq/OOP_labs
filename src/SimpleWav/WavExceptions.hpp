#pragma once

class RIFHeaderCorruptedException : std::runtime_error {
public:
  RIFHeaderCorruptedException() : std::runtime_error("") {

  }
};

class FMTHeaderCorruptedException : std::runtime_error {
public:
  FMTHeaderCorruptedException() : std::runtime_error("") {

  }
};

class DATAHeaderCorruptedException : std::runtime_error {
public:
  DATAHeaderCorruptedException() : std::runtime_error("") {

  }
};
