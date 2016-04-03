#include "User.h"
#include "SwipeStorage.h"

User::User(uint32_t id) : id(id) {
    auto v = Swipe::Storage::get(id);
    name = v.name;
    lastname = v.lastname;
}

uint32_t User::getId() const {
    return id;
}

void User::setId(uint32_t id) {
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
