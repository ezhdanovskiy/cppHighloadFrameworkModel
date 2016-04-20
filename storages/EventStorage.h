#pragma once

#include <User.h>
#include <Logger.h>

#include <map>

namespace Storage {

class Events {
public:
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

    Key add(const Value &value) {
        Key key = storage.size() + 1;
        storage[key] = value;
        LOG("Storage::Event::add(" << key << ", type=" << value.type << ", ownerId=" << value.ownerId << ", text='" << value.text << "')")
        return key;
    };

    Value get(const Key &key) {
        return storage[key].setId(key);
    };

private:
    std::map<Key, Value> storage;
};

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
