cmake_minimum_required(VERSION 3.23)
project(CppCalculator_v2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

add_library(calculator STATIC Calculator.cpp Parser.cpp)
add_executable(calculator_exe main.cpp)

target_link_libraries(calculator_exe PRIVATE calculator)

enable_testing()
add_subdirectory(tests)
