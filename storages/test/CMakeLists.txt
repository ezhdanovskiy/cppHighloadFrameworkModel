project(StoragesTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)

add_gmock_test(UserStorageTest UserStorageTest.cpp)
add_gmock_test_libraries(UserStorageTest UserStorage)

add_gmock_test(ContactsStorageTest ContactsStorageTest.cpp)
add_gmock_test_libraries(ContactsStorageTest ContactsStorage)

add_gmock_test(PostStorageTest PostStorageTest.cpp)
add_gmock_test_libraries(PostStorageTest PostStorage)
