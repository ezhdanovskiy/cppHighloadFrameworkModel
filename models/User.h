#pragma once

#include <string>

#include <SystemDefines.h>

namespace Model {

class User {
public:
    typedef System::TUserId TUserId;

    User(TUserId id);

    User(TUserId id, const std::string &name, const std::string &lastname, const std::string &email) : id(id), name(name), lastname(lastname), email(email) { }

    TUserId getId() const {
        return id;
    }

    void setId(TUserId id) {
        User::id = id;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        User::name = name;
    }

    const std::string &getLastname() const {
        return lastname;
    }

    void setLastname(const std::string &lastname) {
        User::lastname = lastname;
    }

    const std::string &getEmail() const {
        return email;
    }

    void setEmail(const std::string &email) {
        User::email = email;
    }

private:
    TUserId id;
    std::string name;
    std::string lastname;
    std::string email;
};

} // namespace Model
