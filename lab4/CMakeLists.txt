cmake_minimum_required(VERSION 3.10)

project(lab)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20) 
set(CMAKE_CXX_STANDART_REQUIRED ON) 

add_executable(lab_exe main.cpp figure.hpp point.hpp pentagon.hpp hexagon.hpp rhomb.hpp Vector.hpp)  

enable_testing()
add_executable(lab_test tests.cpp figure.hpp point.hpp pentagon.hpp hexagon.hpp rhomb.hpp Vector.hpp)

target_link_libraries(lab_test ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND lab_test)