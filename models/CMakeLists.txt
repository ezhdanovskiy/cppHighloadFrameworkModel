project(Models)

include_directories(${CMAKE_SOURCE_DIR}/libs)

add_library(Models User.cpp)

add_subdirectory(test)
