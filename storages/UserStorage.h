#pragma once

#include <map>
#include <inttypes.h>
#include <string>
#include <iostream>

#include <SystemDefines.h>
#include <Logger.h>

namespace Storage {

class Users {
public:
    typedef System::TUserId Key;

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
        LOG("Storage::Users::add(" << key << ", " << value.name << ", " << value.lastname << ", " << value.email << ")");
        return key;
    };

    Value get(const Key &key) {
        LOG("Storage::Users::add(" << key << ", " << storage[key].name << ", " << storage[key].lastname << ", " << storage[key].email << ")");
        return storage[key].setId(key);
    };

    static Users &getInstance() {
        static Users instance;
        return instance;
    }

private:
    std::map<Key, Value> storage;

    Users() { };
};

} // namespace Storage
