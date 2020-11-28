cmake_minimum_required(VERSION 3.17)
project(tests_)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(headers)

add_executable(tests_
        source_gtest.cpp
        ${SOURCES}
        link_gtest.cpp headers/link_gtest.h)
#add_executable(vector_test
#        ../src/vector.h
#        vector_test.cpp)
#add_executable(queue_test
#        ../src/queue.h
#        queue_test.cpp)
#add_executable(stack_test
#        ../src/stack.h
#        stack_test.cpp)


target_link_libraries(tests_ gtest gtest_main)
add_test(tests_ tests_)
#target_link_libraries(tests_ data_structures)
