project(Storages)

add_library(UserStorage UserStorage.cpp)
add_library(ContactsStorage Contacts.cpp)

add_subdirectory(test)
