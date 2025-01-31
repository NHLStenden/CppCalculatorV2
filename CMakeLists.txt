cmake_minimum_required(VERSION 3.30)
project(CppCalculator_v2)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppCalculator_v2 main.cpp
        Calculator.cpp
        Parser.cpp)

# Google Test instellen
enable_testing()
add_subdirectory(tests/googletest)

# Testbestand compileren en linken met Google Test
add_executable(calculator_tests tests/test_calculator.cpp
        Calculator.cpp Parser.cpp)
target_link_libraries(calculator_tests gtest gtest_main)
add_test(NAME CalculatorTests COMMAND calculator_tests)
