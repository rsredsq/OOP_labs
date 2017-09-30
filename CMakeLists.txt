cmake_minimum_required(VERSION 3.8)
project(lab2)

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(lab1_iniparser)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/StatisticMultiset.cpp src/StatisticMultiset.hpp libs/LRUCache11.hpp)
link_libraries(${Boost_LIBRARIES})
add_executable(lab2 ${SOURCE_FILES})