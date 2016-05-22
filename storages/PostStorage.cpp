#include "PostStorage.h"

#include <Logger.h>

namespace Storage {

Posts::Key Posts::add(const Value &value) {
    Key key = static_cast<Key>(storage.size() + 1);
    storage[key] = value;
    LOG("Storage::Post::add(" << key << ", type=" << value.type << ", ownerId=" << value.ownerId << ", text='" << value.text << "')");
    return key;
};

Posts::Value Posts::get(const Key &key) {
    auto it = storage.find(key);
    if (it != storage.end()) {
        it->second.id = key;
        LOG("Storage::Post::get(" << key << ", type=" << it->second.type << ", ownerId=" << it->second.ownerId << ", text='" << it->second.text << "')");
        return it->second;
    }
    return Value();
};

bool Posts::del(const Key &key) {
    LOG("Storage::Post::del(" << key << ")");
    return storage.erase(key) > 0;
};

} // namespace Storage
