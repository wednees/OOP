cmake_minimum_required(VERSION 3.10)
#требования к версии

project(lab)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20) #стандарт языка си++
set(CMAKE_CXX_STANDART_REQUIRED ON) #без соответствия стандарту не будет собран

add_executable(lab_exe main.cpp figure.hpp point.hpp pentagon.hpp hexagon.hpp rhomb.hpp Vector.hpp)  
#fLRp - запуск main программы

enable_testing() #указывает CMake, что планируется использование CTest
add_executable(lab_test tests.cpp figure.hpp point.hpp pentagon.hpp hexagon.hpp rhomb.hpp Vector.hpp)
#fLRt - запуск тестов отдельно для функции

target_link_libraries(lab_test ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND lab_test)