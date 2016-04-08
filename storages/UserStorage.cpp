#include "UserStorage.h"

#include <iostream>

namespace Storage {
namespace User {

class UsersStorage {
public:

    void add(const Key &key, const Value &value) {
        storage[key] = value;
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

void add(const Key &key, const Value &value) {
    UsersStorage::getInstance().add(key, value);
};

Value get(const Key &key) {
    return UsersStorage::getInstance().get(key);
};

}
}
