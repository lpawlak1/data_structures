cmake_minimum_required(VERSION 3.17)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(data_structures
        src/array_container.h
        src/container.h
        src/link_vector.h
        src/list.h
        src/main.cpp
        src/queue.cpp
        src/queue.h
        src/stack.cpp
        src/stack.h
        src/vector.h
        tests/link_vector_test.cpp
        tests/stack_test.cpp
        )
add_executable(linker_vector
        src/link_vector.h
        tests/link_vector_test.cpp )
add_executable(vector_test
        src/vector.h
        tests/vector_test.cpp)
