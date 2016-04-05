project(StoragesTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)

add_gmock_test(SwipeStorageTest SwipeStorageTest.cpp)
target_link_libraries(SwipeStorageTest UserStorage)
