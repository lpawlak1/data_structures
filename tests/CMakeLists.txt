cmake_minimum_required(VERSION 3.16)
project(tests_)

enable_testing()
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(headers)
file(GLOB test_files "./*.cpp" "headers/*.h")

add_executable(tests_
        source_gtest.cpp
        ${SOURCES}
        ${test_files}
        )


target_link_libraries(tests_ ${CONAN_LIBS})
add_test(tests_ tests_)
