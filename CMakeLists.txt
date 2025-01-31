cmake_minimum_required(VERSION 3.25)
project(CppCalculator_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppCalculator_v2 main.cpp
        Calculator.cpp
        Parser.cpp)

