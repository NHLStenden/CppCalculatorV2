# GoogleTest toevoegen (als submodule)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Test-executable aanmaken
add_executable(calculator_tests test_calculator.cpp test_parser.cpp)
target_link_libraries(calculator_tests PRIVATE calculator gtest gtest_main)

# Tests registreren
include(GoogleTest)
gtest_discover_tests(calculator_tests)
