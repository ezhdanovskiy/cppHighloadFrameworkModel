#pragma once

#include <map>
#include <inttypes.h>
#include <string>

namespace Storage {
namespace User {

typedef uint64_t Key;

struct Value {
    Value() { }

    Value(const std::string &name, const std::string &lastname) : name(name), lastname(lastname) { }

    Value& setId(Key id) {
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
