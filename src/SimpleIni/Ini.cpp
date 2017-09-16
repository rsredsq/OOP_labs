#include <iostream>
#include <fstream>

#include "Ini.hpp"
#include "IniParser.hpp"

namespace SimpleIni {
  Ini Ini::ResolveFromFile(const std::string& fileName) throw(FileOpenException) {
    std::wifstream fileStream(fileName);

    if (!fileStream.is_open())
      throw FileOpenException(fileName.c_str());

    IniParser parser(fileStream);
    return parser.resolveIni();
  }

  Ini Ini::ResolveFromContent(std::wstringstream stringStream) {
    IniParser parser(stringStream);
    return parser.resolveIni();
  }
}