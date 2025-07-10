cmake_minimum_required(VERSION 3.22)
project(CalcGTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CalcLib
        ICalculator.h
        SimpleCalculator.h SimpleCalculator.cpp
        IHistory.h
        InMemoryHistory.h InMemoryHistory.cpp
)

include(FetchContent)
FetchContent_Declare(
        googleTest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        )

FetchContent_MakeAvailable(googleTest)

enable_testing()

add_executable(CalcBaseOperationsTests
        tests/CalcBaseOperationsTests.cpp
)
target_link_libraries(CalcBaseOperationsTests 
        PRIVATE 
        CalcLib 
        gtest 
        gtest_main
        gmock
        gmock_main
)

add_executable(CalcBoundaryOperationsTests
        tests/CalcBoundaryOperationsTests.cpp
)
target_link_libraries(CalcBoundaryOperationsTests 
        PRIVATE 
        CalcLib 
        gtest 
        gtest_main
)

add_executable(HistoryTests 
        tests/HistoryTests.cpp
)
target_link_libraries(HistoryTests 
        PRIVATE 
        CalcLib 
        gtest 
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(CalcBaseOperationsTests)
gtest_discover_tests(CalcBoundaryOperationsTests)
gtest_discover_tests(HistoryTests)

#coverage
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Adding coverage flags")

    target_compile_options(CalcLib PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    
    target_compile_options(CalcBaseOperationsTests PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_libraries(CalcBaseOperationsTests PRIVATE --coverage)
    
    target_compile_options(CalcBoundaryOperationsTests PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_libraries(CalcBoundaryOperationsTests PRIVATE --coverage)
    
    target_compile_options(HistoryTests PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_libraries(HistoryTests PRIVATE --coverage)
endif()