cmake_minimum_required(VERSION 3.25)
project(CppCalculator_v2)

set(CMAKE_CXX_STANDARD 20)


add_library(calculator STATIC Calculator.cpp Parser.cpp)
add_executable(calculator_exe main.cpp)
target_link_libraries(calculator_exe PRIVATE calculator)

enable_testing()
add_subdirectory(tests)
