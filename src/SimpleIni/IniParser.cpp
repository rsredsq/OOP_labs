#include <regex>
#include <iostream>
#include <boost/regex.hpp>

#include "IniParser.hpp"

namespace SimpleIni {

  IniParser::IniParser(std::wistream& contentStream)
      : contentStream(contentStream) {

  }

  Ini IniParser::resolveIni() const {

    boost::wregex regex(L"(?:;+.*)?$|\\[\\s*(?<section>\\w+)\\s*\\]"
                         "|(?<key>\\w+)"
                         "\\s*=\\s*"
                         "(?<value>.*?)"
                         "(?:;+.*)?$");

    Sections sections;
    Parameters params;

    std::wstring currStr;

    std::wstring section;
    std::wstring key;
    std::wstring value;

    while (std::getline(contentStream, currStr)) {
      boost::wsmatch match;
      boost::regex_match(currStr, match, regex);

//      section = match["section"].length() > 0 ? match["section"] : section;
//      key = match["key"].length() > 0 ? match["key"] : key;
//      value = match["value"].length() > 0 ? match["value"] : value;
    }

    return Ini(sections);
  }

  void parseSection(const std::wstring& sectionName) {
    
  }

}