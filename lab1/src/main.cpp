#include <iostream>

#include "SimpleIni/Ini.hpp"


using namespace SimpleIni;

//example of usage
int main() {

  auto iniFile = Ini::ResolveFromFile("ini/lab01_input_correct_09.ini");

  auto testVal = iniFile.get<double>("DEMODS", "SampleRate");

  std::cout << testVal;

  return 0;
}
