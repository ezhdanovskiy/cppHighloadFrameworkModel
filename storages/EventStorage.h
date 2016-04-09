#pragma once

#include <User.h>

#include <map>

namespace Storage {
namespace Event {

typedef uint32_t Key;

struct Value {
    Value() { }

    Value(int type, Model::User::TUserId ownerId, const std::string &text) : type(type), ownerId(ownerId), text(text) { }

    Value &setId(Key id) {
        Value::id = id;
        return *this;
    }

    Key id = 0;
    int type;
    Model::User::TUserId ownerId;
    std::string text;
};

Key add(const Value &value);

Value get(const Key &key);

}
}
