#include <iostream>

#include "IniParser.hpp"

namespace SimpleIni {

  IniParser::IniParser(std::istream& contentStream)
      : contentStream(contentStream), regex("(?:;+.*)?$"
                                                "|\\[\\s*(?<section>\\w+)\\s*\\]"
                                                "|(?<key>\\w+)"
                                                "\\s*=\\s*"
                                                "(?<value>.*?)"
                                                "(?:;+.*)?$") {

  }

  Ini IniParser::resolveIni() const {
    Sections sections;

    std::string currStr;

    while (std::getline(contentStream, currStr)) {
      boost::smatch match;
      boost::regex_match(currStr, match, regex);

      if (match["section"].length() > 0) {
        sections[match["section"]] = parseSection(match["section"]);
      }
    }

    return Ini(sections);
  }

  Parameters IniParser::parseSection(const std::string& sectionName) const {
    boost::smatch match;
    Parameters params;
    do {
      std::string currStr;
      std::getline(contentStream, currStr);
      boost::regex_match(currStr, match, regex);

      params.insert({match["key"], match["value"]});

    } while (!match["section"].length() && !contentStream.eof());

    return params;
  }

}
