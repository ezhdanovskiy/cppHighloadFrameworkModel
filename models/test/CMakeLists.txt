project(ModelsTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)

add_gmock_test(UserTest UserTest.cpp)
add_gmock_test_libraries(UserTest UserStorage UserModel)
