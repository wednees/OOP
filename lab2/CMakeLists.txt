cmake_minimum_required(VERSION 3.10)
project(lab)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp func.cpp)

enable_testing()

add_executable(tests01 tests01.cpp  func.cpp)
target_link_libraries(tests01 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests01)