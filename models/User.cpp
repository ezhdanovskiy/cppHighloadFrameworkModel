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

} // namespace Model
