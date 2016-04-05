cmake_minimum_required(VERSION 2.8)
project(cppSwipe)

set(BIN_NAME swipe)

enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

include_directories(${CMAKE_SOURCE_DIR}/storages)
include_directories(${CMAKE_SOURCE_DIR}/models)

add_subdirectory(${CMAKE_SOURCE_DIR}/gmock)
add_subdirectory(${CMAKE_SOURCE_DIR}/storages)
add_subdirectory(${CMAKE_SOURCE_DIR}/models)

set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
add_executable(${BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${BIN_NAME} Models)
