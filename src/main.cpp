#include <iostream>

#include "SimpleIni/Ini.hpp"


using namespace SimpleIni;

int main() {

  auto iniFile = Ini::ResolveFromFile("test.ini");

  auto testVal = iniFile.get<int>("DEBUG", "PlentySockMaxQSize");

  std::wcout << testVal;

  return 0;
}
