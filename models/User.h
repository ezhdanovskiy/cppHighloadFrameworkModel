#pragma once

#include <string>

#include <SystemDefines.h>

namespace Model {

class User {
public:
    typedef Swipe::TUserId TUserId;

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

} // namespace Model
