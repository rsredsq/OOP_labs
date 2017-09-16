#include <iostream>

#include "SimpleIni/Ini.hpp"


using namespace SimpleIni;

int main() {

  auto iniFile = Ini::ResolveFromFile("test.ini");

  auto testSection = iniFile.getSection(L"DEBUG");

  std::wcout << testSection.at(L"PlentySockMaxQSize");

  return 0;
}