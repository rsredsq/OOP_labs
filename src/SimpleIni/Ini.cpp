#include <iostream>
#include <fstream>

#include "Ini.hpp"
#include "IniParser.hpp"

namespace SimpleIni {
  Ini Ini::ResolveFromFile(const std::string& fileName) throw(FileOpenException) {
    std::ifstream fileStream(fileName);

    if (!fileStream.is_open())
      throw FileOpenException(fileName);

    IniParser parser(fileStream);
    return parser.resolveIni();
  }

  Ini Ini::ResolveFromContent(std::stringstream stringStream) {
    IniParser parser(stringStream);
    return parser.resolveIni();
  }

  template<>
  const std::string Ini::get<std::string>(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    checkRange(sectionName, paramName);
    auto value = sections.at(sectionName).at(paramName);
    return value;
  }

  template<>
  const int Ini::get<int>(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    auto value = get<std::string>(sectionName, paramName);
    return std::stoi(value);
  }

  template<>
  const double Ini::get<double>(const std::string& sectionName, const std::string& paramName) const
  throw(SectionNotFoundException, ParamNotFoundException) {
    auto value = get<std::string>(sectionName, paramName);
    return std::stod(value);
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