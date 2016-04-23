project(SwipeServerTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)
include(${CMAKE_SOURCE_DIR}/storages/CMakeLibs.cmake)

add_gmock_test(SwipeServerTest SwipeServerTest.cpp ../src/SwipeImpl.cpp)
target_link_libraries(SwipeServerTest UserModel ${STORAGE_LIBS})
