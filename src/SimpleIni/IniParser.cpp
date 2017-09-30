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

  Ini IniParser::resolveIni() {
    Sections sections;

    while (!contentStream.eof()) {
      matchCurrentLine();
      bool sectionMatched = currentLineMatch["section"].matched;

      if (sectionMatched) {
        std::string sectionName = currentLineMatch["section"];
        sections[sectionName] = parseSection();
        continue;
      }
      nextLine();
    }

    return Ini(sections);
  }

  Parameters IniParser::parseSection() {
    Parameters currentSectionParams;
    while (nextLine() && matchCurrentLine() && !currentLineMatch["section"].matched) {
      if (currentLine.empty()) continue;
      if (!currentLineMatch["key"].matched) continue;
      currentSectionParams.insert({currentLineMatch["key"], currentLineMatch["value"]});
    }
    return currentSectionParams;
  }

  inline bool IniParser::matchCurrentLine() {
    boost::trim(currentLine);
    return boost::regex_match(currentLine, currentLineMatch, regex);
  }

  inline std::istream& IniParser::nextLine() {
    return std::getline(contentStream, currentLine);
  }

}
