#include <iostream>
#include <fstream>

#include "Ini.hpp"
#include "IniParser.hpp"

namespace SimpleIni {
  Ini Ini::ResolveFromFile(const std::string& fileName) throw(FileOpenException) {
    std::ifstream fileStream(fileName);

    if (!fileStream.is_open())
      throw FileOpenException(fileName);

    return ResolveFromContent(fileStream);
  }

  Ini Ini::ResolveFromContent(std::istream& stream) {
    IniParser parser(stream);
    return std::move(parser.resolveIni());
  }

  template<>
  std::string Ini::get<std::string>(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    checkRange(sectionName, paramName);
    auto value = sections.at(sectionName).at(paramName);
    return value;
  }

  template<>
  int Ini::get<int>(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    auto value = get<std::string>(sectionName, paramName);
    return std::stoi(value);
  }

  template<>
  double Ini::get<double>(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    auto value = get<std::string>(sectionName, paramName);
    return std::stod(value);
  }

  bool Ini::hasSection(const std::string& sectionName) const noexcept {
    return sections.count(sectionName) > 0;
  }

  bool Ini::hasParameter(const std::string& sectionName, const std::string& paramName) const noexcept {
    return hasSection(sectionName) && sections.at(sectionName).count(paramName) > 0;
  }

  void Ini::checkRange(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    if (!sections.count(sectionName)) {
      throw SectionNotFoundException(sectionName);
    }
    if (!sections.at(sectionName).count(paramName)) {
      throw ParamNotFoundException(paramName);
    }
  }
}