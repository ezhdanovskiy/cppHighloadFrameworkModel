#ifndef CPPSWIPE_USER_H
#define CPPSWIPE_USER_H

#include <string>

class User {
public:
    User(uint32_t id);

    uint32_t getId() const;
    void setId(uint32_t id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getLastname() const;
    void setLastname(const std::string &lastname);

private:
    uint32_t id;
    std::string name;
    std::string lastname;
};

#endif //CPPSWIPE_USER_H
