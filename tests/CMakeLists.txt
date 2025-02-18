# Google Test downloaden en toevoegen
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Test-executable aanmaken
add_executable(calculator_tests
        test_calculator.cpp
        bulk_tests_division.cpp
        bulk_tests_multiply.cpp
        parser_tests.cpp)

# Linken met Google Test en de hoofdcode
target_link_libraries(calculator_tests PRIVATE calculator gtest gtest_main)

# Zorg dat de include-paths correct zijn
target_include_directories(calculator_tests PRIVATE ${googletest_SOURCE_DIR}/googletest/include)

# Tests automatisch detecteren
include(GoogleTest)
gtest_discover_tests(calculator_tests)
