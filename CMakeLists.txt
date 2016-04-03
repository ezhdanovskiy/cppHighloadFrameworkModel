cmake_minimum_required(VERSION 2.8)
project(cppSwipe)

set(BIN_NAME swipe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(gmock)
add_subdirectory(models)

include_directories(models)

set(SOURCE_FILES
    src/main.cpp
)
add_executable(${BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${BIN_NAME} Models)
