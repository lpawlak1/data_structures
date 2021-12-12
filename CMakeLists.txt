cmake_minimum_required(VERSION 3.16)
project(data_structure)

#set(CMAKE_CXX_STANDARD 11)
add_definitions("-std=c++11")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(src)

file(GLOB SOURCES "src/*.hpp" "src/*.h")


#add_subdirectory(lib/googletest)
add_subdirectory(src)
add_subdirectory(tests)



#add_executable(timer timer.cpp)
#target_link_libraries(timer ${CONAN_LIBS})
