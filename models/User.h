#pragma once

#include <string>

namespace Model {

class User {
public:
    typedef uint64_t TUserId;

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
