#include <iostream>
#include <fstream>

#include "Ini.hpp"
#include "IniParser.hpp"

namespace SimpleIni {
  Ini Ini::ResolveFromFile(std::string fileName) {
    std::wifstream fileStream(fileName);
    IniParser parser(fileStream);
    return parser.resolveIni();
  }
}