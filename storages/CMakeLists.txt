project(Storages)

add_library(UserStorage UserStorage.cpp)
add_library(ContactsStorage ContactsStorage.cpp)
add_library(PostStorage PostStorage.cpp)

add_subdirectory(test)
