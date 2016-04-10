project(SwipeServerTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)

add_gmock_test(SwipeServerTest SwipeServerTest.cpp ../src/Subscriptions.cpp)
target_link_libraries(SwipeServerTest UserStorage ContactsStorage EventStorage Models)
