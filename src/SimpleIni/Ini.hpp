#pragma once

#include <string>
#include <sstream>
#include <unordered_map>
#include "exceptions/FileOpenException.hpp"

namespace SimpleIni {
  class Ini;

  struct Section;

  using Parameters = std::unordered_map<std::wstring, std::wstring>;
  using Sections = std::unordered_map<std::wstring, Parameters>;

  class Ini {
    friend class IniParser;

  public:
    static Ini ResolveFromFile(const std::string& fileName)
    throw(FileOpenException);

    static Ini ResolveFromContent(std::wstringstream stringStream);

    Ini(const Ini&) = delete;

    Ini& operator=(const Ini&) = delete;

    ~Ini() = default;

    Ini(Ini&&) = default;

    Ini& operator=(Ini&&) = default;

    const Parameters& getSection(const std::wstring& sectionName) const {
      return sections.at(sectionName);
    }

  private:
    explicit Ini(Sections sections)
        : sections(std::move(sections)) {};


    Sections sections;
  };
}


