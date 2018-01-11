cmake_minimum_required(VERSION 3.8)
project(lab3)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/SimpleWav/WavReader.cpp src/SimpleWav/WavReader.hpp
    src/SimpleWav/WavWriter.cpp src/SimpleWav/WavWriter.hpp
    src/SimpleWav/Wav.cpp src/SimpleWav/Wav.hpp
    src/SimpleWav/WavHeader.hpp src/SimpleWav/WavExceptions.hpp)

link_libraries(${Boost_LIBRARIES})
add_executable(lab3 ${SOURCE_FILES})