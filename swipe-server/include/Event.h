#pragma once

#include <inttypes.h>
#include <string>

#include <User.h>

#include "SwipeDefines.h"

namespace Swipe {

class Event {
public:
    enum Type {
        open, friendsOnly, group
    };
    typedef uint32_t TEventId;

    Event(Type type, const Model::User &owner, const std::string &text);

private:
    TEventId id = 0;
    Type type;
    TUserId ownerId;
    std::string text;

public:
    const std::string &getText() const;

    void setText(const std::string &text);
};

} // namespace Swipe
