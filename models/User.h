#ifndef CPPSWIPE_USER_H
#define CPPSWIPE_USER_H

#include <string>

namespace Model {

class User {
public:
    typedef uint32_t TUserId;

    User(TUserId id);

    TUserId getId() const;

    void setId(TUserId id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getLastname() const;

    void setLastname(const std::string &lastname);

private:
    TUserId id;
    std::string name;
    std::string lastname;
};

}

#endif //CPPSWIPE_USER_H
