#pragma once

#include <map>

#include <SystemDefines.h>
#include <Logger.h>

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

    Key add(const Value &value) {
        Key key = static_cast<Key>(storage.size() + 1);
        storage[key] = value;
        LOG("Storage::Post::add(" << key << ", type=" << value.type << ", ownerId=" << value.ownerId << ", text='" << value.text << "')");
        return key;
    };

    Value get(const Key &key) {
        auto it = storage.find(key);
        if (it != storage.end()) {
            it->second.id = key;
            LOG("Storage::Post::get(" << key << ", type=" << it->second.type << ", ownerId=" << it->second.ownerId << ", text='" << it->second.text << "')");
            return it->second;
        }
        return Value();
    };

    bool del(const Key &key) {
        LOG("Storage::Post::del(" << key << ")");
        return storage.erase(key) > 0;
    };

private:
    std::map<Key, Value> storage;
};

} // namespace Storage
