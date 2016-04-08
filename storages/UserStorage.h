#pragma once

#include <map>

namespace Storage {
namespace User {

typedef uint32_t Key;

struct Value {
    Key id;
    std::string name;
    std::string lastname;
};

void add(const Key &key, const Value &value);

Value get(const Key &key);

}
}
