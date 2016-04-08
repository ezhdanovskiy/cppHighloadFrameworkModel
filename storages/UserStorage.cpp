#include "UserStorage.h"

#include <iostream>

namespace Storage {
namespace User {

class UsersStorage {
public:

    Key add(const Value &value) {
        Key key = storage.size()+1;
        storage[key] = Value(value.name, value.lastname).setId(key);
        return key;
    };

    Value get(const Key &key) {
        return storage[key];
    };

    static UsersStorage &getInstance() {
        static UsersStorage instance;
        return instance;
    }

private:
    std::map<Key, Value> storage;
};

Key add(const Value &value) {
    return UsersStorage::getInstance().add(value);
};

Value get(const Key &key) {
    return UsersStorage::getInstance().get(key);
};

}
}
