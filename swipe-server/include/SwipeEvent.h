#pragma once

#include <User.h>

#include <inttypes.h>
#include <string>

namespace Model {

class SwipeEvent {
public:
    enum Type {
        publicEv, friendsOnly, group
    };
    typedef uint32_t TEventId;

    SwipeEvent(Type type, TEventId id, const Model::User &owner, const std::string &text);

private:
    Type type;
    TEventId id;
    Model::User::TUserId ownerId;
    std::string text;
public:
    const std::string &getText() const;

    void setText(const std::string &text);
};

}
