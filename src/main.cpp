#include <iostream>

#include "SimpleIni/Ini.hpp"


using namespace SimpleIni;

int main() {

  auto iniFile = Ini::ResolveFromFile("ini/lab01_input_correct_09.ini");

//  auto testVal = iniFile.get<int>("COMMON", "LogBsonMessages");
//
//  std::cout << testVal;

  return 0;
}
