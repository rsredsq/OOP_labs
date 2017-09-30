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
    Ini resolveIni();

    Parameters parseSection();
    bool matchCurrentLine();
    std::istream& nextLine();

    std::istream& contentStream;

    boost::regex regex;
    boost::smatch currentLineMatch;
    std::string currentLine;
  };
}


