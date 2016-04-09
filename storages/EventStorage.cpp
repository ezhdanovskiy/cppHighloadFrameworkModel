#include "UserStorage.h"
#include "EventStorage.h"

#include <iostream>

namespace Storage {
namespace Event {

class Storage {
public:

    Key add(const Value &value) {
        Key key = storage.size()+1;
        storage[key] = Value(value.type, value.ownerId, value.text).setId(key);
        return key;
    };

    Value get(const Key &key) {
        return storage[key];
    };

    static Storage &getInstance() {
        static Storage instance;
        return instance;
    }

private:
    std::map<Key, Value> storage;
};

Key add(const Value &value) {
    return Storage::getInstance().add(value);
};

Value get(const Key &key) {
    return Storage::getInstance().get(key);
};

}
}
