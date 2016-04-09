#pragma once

#include <User.h>

#include <inttypes.h>
#include <string>

namespace Swipe {

class Event {
public:
    enum Type {
        publicEv, friendsOnly, group
    };
    typedef uint32_t TEventId;

    Event(Type type, const Model::User &owner, const std::string &text);

private:
    TEventId id = 0;
    Type type;
    Model::User::TUserId ownerId;
    std::string text;
public:
    const std::string &getText() const;

    void setText(const std::string &text);
};

}
