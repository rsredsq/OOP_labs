#include <iostream>

#include "SimpleIni/Ini.hpp"


using namespace SimpleIni;

int main() {

  auto iniFile = Ini::ResolveFromFile("test.ini");

  auto val = iniFile.getSection(L"Test");

  std::wcout << val.at(L"TestKey");

  return 0;
}