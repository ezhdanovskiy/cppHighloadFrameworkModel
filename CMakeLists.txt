cmake_minimum_required(VERSION 2.8)
project(cppSwipe)

set(BIN_NAME swipe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

add_subdirectory(${CMAKE_SOURCE_DIR}/gmock)
add_subdirectory(${CMAKE_SOURCE_DIR}/models)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs)

include_directories(${CMAKE_SOURCE_DIR}/models)
include_directories(${CMAKE_SOURCE_DIR}/libs)

set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
add_executable(${BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${BIN_NAME} Models)
