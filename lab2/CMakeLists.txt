cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(lab2)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/StatisticMultiset.cpp src/StatisticMultiset.hpp)
link_libraries(${Boost_LIBRARIES})
add_executable(lab2 ${SOURCE_FILES})