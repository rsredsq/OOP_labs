#pragma once

#include <string>
#include <sstream>
#include <unordered_map>
#include "exceptions/FileOpenException.hpp"
#include "exceptions/ParamNotFoundException.hpp"
#include "exceptions/SectionNotFoundException.hpp"

namespace SimpleIni {
  class Ini;

  using Parameters = std::unordered_map<std::string, std::string>;
  using Sections = std::unordered_map<std::string, Parameters>;

  class Ini {
    friend class IniParser;

  public:
    static Ini ResolveFromFile(const std::string& fileName)
    throw(FileOpenException);

    static Ini ResolveFromContent(std::istream& stream);

    Ini(const Ini&) = delete;

    Ini& operator=(const Ini&) = delete;

    ~Ini() = default;

    Ini(Ini&&) = default;

    Ini& operator=(Ini&&) = default;

    template<typename T>
    const T get(const std::string& sectionName, const std::string& paramName) const
    throw(SectionNotFoundException, ParamNotFoundException);

    bool hasSection(const std::string& sectionName) const noexcept;

    bool hasParameter(const std::string& sectionName, const std::string& paramName) const noexcept;

  private:
    explicit Ini(Sections sections)
        : sections(std::move(sections)) {};

    void checkRange(const std::string& sectionName, const std::string& paramName) const
    throw(SectionNotFoundException, ParamNotFoundException);

    Sections sections;
  };
}


