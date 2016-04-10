project(StoragesTests)

include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)

add_gmock_test(UserStorageTest UserStorageTest.cpp)
target_link_libraries(UserStorageTest UserStorage)

add_gmock_test(ContactsStorageTest ContactsStorageTest.cpp)
target_link_libraries(ContactsStorageTest ContactsStorage)

add_gmock_test(EventStorageTest EventStorageTest.cpp)
target_link_libraries(EventStorageTest EventStorage)
