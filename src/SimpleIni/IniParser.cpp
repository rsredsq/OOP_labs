#include "IniParser.hpp"

namespace SimpleIni {

  IniParser::IniParser(const std::wistream& contentStream)
      : contentStream(contentStream) {

  }

  Ini IniParser::resolveIni() const {
    Sections sections;
    Parameters params;
    params.insert(std::make_pair(L"TestKey", L"TestVal"));
    sections.insert({L"Test", params});

    return Ini(sections);
  }

}