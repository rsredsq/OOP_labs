cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(lab1_iniparser)

find_package(Boost REQUIRED COMPONENTS regex)

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/SimpleIni/IniParser.cpp src/SimpleIni/IniParser.hpp src/SimpleIni/Ini.cpp src/SimpleIni/Ini.hpp
    src/SimpleIni/ParserExceptions.hpp)
link_libraries(${Boost_LIBRARIES})
add_executable(lab1_iniparser ${SOURCE_FILES})