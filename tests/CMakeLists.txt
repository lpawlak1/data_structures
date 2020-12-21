cmake_minimum_required(VERSION 3.17)
project(tests_)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(headers)

add_executable(tests_
        source_gtest.cpp
        ${SOURCES}
        link_gtest.cpp headers/link_gtest.h
        queue_gtest.cpp headers/queue_gtest.h
        vector_gtest.cpp headers/vector_gtest.h
        stack_gtest.cpp headers/stack_gtest.h)



target_link_libraries(tests_ gtest gtest_main)
add_test(tests_ tests_)
#target_link_libraries(tests_ data_structures)
