#include "User.h"

#include <UserStorage.h>
#include <Logger.h>

namespace Model {

User::User(TUserId id) : id(id) {
    auto v = Storage::Users::getInstance().get(id);
    name = v.name;
    lastname = v.lastname;
    LOG("Hello, I am " << name << "! id=" << id);
}

} // namespace Model
