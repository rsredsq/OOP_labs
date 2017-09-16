#pragma once

#include <string>
#include <sstream>
#include <boost/regex.hpp>
#include "Ini.hpp"

namespace SimpleIni {
  class IniParser {
    friend class Ini;

  public:
    explicit IniParser(std::istream& contentStream);

    IniParser(const IniParser&) = delete;

    IniParser& operator=(const IniParser&) = delete;

  private:
    Ini resolveIni() const;

    Parameters parseSection(const std::string& sectionName) const;

    std::istream& contentStream;

    boost::regex regex;
  };
}


