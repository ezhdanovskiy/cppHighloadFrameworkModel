project(ModelsTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)

add_gmock_test(UserTest UserTest.cpp)
target_link_libraries(UserTest UserStorage UserModel)
