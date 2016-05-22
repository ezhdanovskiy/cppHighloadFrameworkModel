#pragma once

#include <map>
#include <string>

#include <SystemDefines.h>

namespace Storage {

class Posts {
public:
    typedef System::TUserId Key;

    struct Value {
        Value() { }

        Value(int type, System::TUserId ownerId, const std::string &text) : type(type), ownerId(ownerId), text(text) { }

        Key id = 0;
        int type;
        System::TUserId ownerId;
        std::string text;
    };

    Key add(const Value &value);

    Value get(const Key &key);

    bool del(const Key &key);

private:
    std::map<Key, Value> storage;
};

} // namespace Storage
