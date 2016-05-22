#pragma once

#include <map>

#include <SystemDefines.h>

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

    Key add(const Value &value);

    Value get(const Key &key);

    static Users &getInstance() {
        static Users instance;
        return instance;
    }

private:
    std::map<Key, Value> storage;

    Users() { };
};

} // namespace Storage
