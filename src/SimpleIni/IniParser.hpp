#pragma once

#include <string>
#include <sstream>
#include "Ini.hpp"

namespace SimpleIni {
  class IniParser {
    friend class Ini;

  public:
    explicit IniParser(std::wistream& contentStream);

    IniParser(const IniParser&) = delete;

    IniParser& operator=(const IniParser&) = delete;

  private:
    Ini resolveIni() const;

    Ini tryParseIni() const;

    std::wistream& contentStream;
  };
}


