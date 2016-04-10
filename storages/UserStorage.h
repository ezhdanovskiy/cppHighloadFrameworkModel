#pragma once

#include <map>
#include <inttypes.h>
#include <string>

namespace Storage {

class Users {
public:
    typedef uint64_t Key;

    struct Value {
        Value() { }

        Value(const std::string &name, const std::string &lastname, const std::string &email) : name(name), lastname(lastname), email(email) { }

        Value &setId(Key id) {
            Value::id = id;
            return *this;
        }

        Key id = 0;
        std::string name;
        std::string lastname;
        std::string email;
    };

    Key add(const Value &value) {
        Key key = storage.size() + 1;
        storage[key] = value;
        return key;
    };

    Value get(const Key &key) {
        return storage[key].setId(key);
    };

private:
    std::map<Key, Value> storage;
};

namespace User {

typedef uint64_t Key;

struct Value {
    Value() { }

    Value(const std::string &name, const std::string &lastname) : name(name), lastname(lastname) { }

    Value &setId(Key id) {
        Value::id = id;
        return *this;
    }

    Key id = 0;
    std::string name;
    std::string lastname;
};

Key add(const Value &value);

Value get(const Key &key);

}
}
