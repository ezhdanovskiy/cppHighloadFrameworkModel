#ifndef CPPSWIPE_STORAGE_H
#define CPPSWIPE_STORAGE_H

#include <map>

namespace Swipe {
namespace Storage {

typedef uint32_t Key;

struct Value {
    Key id;
    std::string name;
    std::string lastname;
};

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

static void addUser(const Key &key, const Value &value) {
    UsersStorage::getInstance().add(key, value);
};

static Value getUser(const Key &key) {
    return UsersStorage::getInstance().get(key);
};

}
}

#endif //CPPSWIPE_STORAGE_H
