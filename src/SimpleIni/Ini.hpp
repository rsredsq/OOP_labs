#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

namespace SimpleIni {
  class Ini;
  struct Section;

  using Parameters = std::unordered_map<std::wstring, std::wstring>;
  using Sections = std::unordered_map<std::wstring, Parameters>;

  class Ini {
    friend class IniParser;

  public:
    static Ini ResolveFromFile(std::string fileName);

    static Ini ResolveFromContent(std::wifstream stringStream);

    Ini(const Ini&) = delete;

    Ini& operator=(const Ini&) = delete;

    Ini(Ini&&) = default;

    const Parameters& getSection(const std::wstring& sectionName) const {
      return sections.at(sectionName);
    }

  private:
    explicit Ini(Sections sections)
        : sections(std::move(sections)) {};
    Sections sections;
  };
}


