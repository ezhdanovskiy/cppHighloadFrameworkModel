#pragma once

#include <inttypes.h>
#include <string>

namespace Model {

class SwipeEvent {
public:
    enum Type {
        publicEv, friendsOnly, group
    };
    typedef uint32_t TEventId;

    SwipeEvent(Type type, TEventId id);

private:
    Type type;
    TEventId id;
    std::string text;
public:
    const std::string &getText() const;

    void setText(const std::string &text);
};

}
