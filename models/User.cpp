#include "User.h"

#include <UserStorage.h>

#include <iostream>

namespace Model {

User::User(TUserId id) : id(id) {
    auto v = Storage::User::get(id);
    name = v.name;
    lastname = v.lastname;
    std::cout << "Hello, I am " << name << "! id=" << id << std::endl;
}

User::TUserId User::getId() const {
    return id;
}

void User::setId(TUserId id) {
    User::id = id;
}

const std::string& User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

const std::string& User::getLastname() const {
    return lastname;
}

void User::setLastname(const std::string &lastname) {
    User::lastname = lastname;
}

} // namespace Model
