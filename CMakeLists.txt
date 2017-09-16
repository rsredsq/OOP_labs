cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(lab1_iniparser)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/SimpleIni/IniParser.cpp src/SimpleIni/IniParser.hpp src/SimpleIni/Ini.cpp src/SimpleIni/Ini.hpp
    src/SimpleIni/exceptions/FileOpenException.hpp src/SimpleIni/exceptions/ParamNotFoundException.hpp src/SimpleIni/exceptions/SectionNotFoundException.hpp)
link_libraries(boost_regex)
add_executable(lab1_iniparser ${SOURCE_FILES})