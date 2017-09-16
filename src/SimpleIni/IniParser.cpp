#include <iostream>
#include <boost/algorithm/string.hpp>

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
      auto match = matchString(currStr);

      if (match["section"].matched) {
        std::cout << match["section"] << std::endl;
        sections[match["section"]] = parseSection(match["section"]);
      }
    }

    return Ini(sections);
  }

  Parameters IniParser::parseSection(const std::string& sectionName) const {
    boost::smatch match;
    Parameters params;
    int prevLinePosition;
    do {
      std::string currStr;
      prevLinePosition = contentStream.tellg();
      std::getline(contentStream, currStr);
      boost::trim(currStr);
      if (currStr.empty()) continue;

      boost::regex_match(currStr, match, regex);
      if (!match["key"].matched) continue;

      params.insert({match["key"], match["value"]});
      std::cout << match["key"] << "=" << match["value"] << std::endl;

    } while (!match["section"].matched && !contentStream.eof());

    contentStream.seekg(prevLinePosition);
    return params;
  }

  boost::smatch IniParser::matchString(std::string& str) const {
    boost::trim(str);
    boost::smatch match;
    boost::regex_match(str, match, regex);
    return match;
  }

}
