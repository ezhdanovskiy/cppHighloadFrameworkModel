project(Storages)

add_library(UserStorage UserStorage.cpp)
add_library(ContactsStorage ContactsStorage.cpp)
add_library(EventStorage EventStorage.cpp)

add_subdirectory(test)
