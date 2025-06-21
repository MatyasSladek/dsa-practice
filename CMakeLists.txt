cmake_minimum_required(VERSION 3.31)
project(dsa_practice)

set(CMAKE_CXX_STANDARD 17)

# Find Catch2
find_package(Catch2 3 QUIET)

if(NOT Catch2_FOUND)
    # If Catch2 is not found, fetch it
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v2.13.10
    )
    FetchContent_MakeAvailable(Catch2)
endif()

# Create the sorting test executable
add_executable(sorting_tests
        test_sorting.cpp
        SortingAlgorithms.cpp
)

# Create the recursion test executable
add_executable(recursion_tests
        test_recursion.cpp
        RecursionTypes.cpp
)

# Link Catch2 to both executables
target_link_libraries(sorting_tests PRIVATE Catch2::Catch2)
target_link_libraries(recursion_tests PRIVATE Catch2::Catch2)

# Include directories for both executables
target_include_directories(sorting_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(recursion_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Enable testing
enable_testing()
add_test(NAME sorting_algorithm_tests COMMAND sorting_tests)
add_test(NAME recursion_algorithm_tests COMMAND recursion_tests)