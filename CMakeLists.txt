cmake_minimum_required(VERSION 2.8)
project(cppSwipe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(gmock)

include_directories(models)

set(SOURCE_FILES
    src/main.cpp
    models/User.cpp
)
add_executable(swipe ${SOURCE_FILES})