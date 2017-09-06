#include "SimpleIni/Ini.hpp"

#include <iostream>

using namespace SimpleIni;

Ini resolveIni(std::string fileName) {
  return Ini::ResolveFromFile(std::move(fileName));
}

int main() {

  auto iniFile = resolveIni("test.ini");

  auto val = iniFile.getSection(L"Test");

  std::wcout << val.at(L"TestKey");

  return 0;
}