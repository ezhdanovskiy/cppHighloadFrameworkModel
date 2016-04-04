#ifndef CPPSWIPE_STORAGE_H
#define CPPSWIPE_STORAGE_H

#include <map>

namespace Swipe {

class Storage {
public:

    typedef uint32_t Key;

    struct Value {
        Key id;
        std::string name;
        std::string lastname;
    };
    typedef std::map<Key, Value> TStorage;

    static void add(const Key &key, const Value &value) {
        getStorage()[key] = value;
    };

    static Value get(const Key &key) {
        return getStorage()[key];
    };

private:
    static TStorage& getStorage() {
        static TStorage storage;
        return storage;
    }
};

}

#endif //CPPSWIPE_STORAGE_H
