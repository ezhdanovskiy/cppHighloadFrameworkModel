#ifndef CPPSWIPE_USER_H
#define CPPSWIPE_USER_H

#include <string>

class User {
public:
    User(int id, const std::string &name, const std::string &lastname) : id(id), name(name), lastname(lastname) { }

    int getId() const {
        return id;
    }

    void setId(int id) {
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

private:
    int id;
    std::string name;
    std::string lastname;
};


#endif //CPPSWIPE_USER_H
