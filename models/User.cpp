#include "User.h"

#include <SwipeStorage.h>

#include <iostream>

using namespace std;

Model::User::User(TUserId id) : id(id) {
    auto v = Swipe::Storage::getUser(id);
    name = v.name;
    lastname = v.lastname;
    cout << "Hello, I am " << name << "!" << endl;
}

Model::User::TUserId Model::User::getId() const {
    return id;
}

void Model::User::setId(TUserId id) {
    User::id = id;
}

const std::string& Model::User::getName() const {
    return name;
}

void Model::User::setName(const std::string &name) {
    User::name = name;
}

const std::string& Model::User::getLastname() const {
    return lastname;
}

void Model::User::setLastname(const std::string &lastname) {
    User::lastname = lastname;
}
