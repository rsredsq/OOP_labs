#include <iostream>

#include "IniParser.hpp"

namespace SimpleIni {

  IniParser::IniParser(std::wistream& contentStream)
      : contentStream(contentStream), regex(L"(?:;+.*)?$"
                                                "|\\[\\s*(?<section>\\w+)\\s*\\]"
                                                "|(?<key>\\w+)"
                                                "\\s*=\\s*"
                                                "(?<value>.*?)"
                                                "(?:;+.*)?$") {

  }

  Ini IniParser::resolveIni() const {
    Sections sections;

    std::wstring currStr;

    while (std::getline(contentStream, currStr)) {
      boost::wsmatch match;
      boost::regex_match(currStr, match, regex);

      if (match["section"].length() > 0) {
        sections[match["section"]] = parseSection(match["section"]);
      }
    }

    return Ini(sections);
  }

  Parameters IniParser::parseSection(const std::wstring& sectionName) const {
    boost::wsmatch match;
    Parameters params;
    do {
      std::wstring currStr;
      std::getline(contentStream, currStr);
      boost::regex_match(currStr, match, regex);

      params.insert({match["key"], match["value"]});

    } while (!match["section"].length() && !contentStream.eof());

    return params;
  }

}