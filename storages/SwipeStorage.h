#pragma once

#include <map>
namespace Swipe {
namespace Storage {

typedef uint32_t Key;

struct Value {
    Key id;
    std::string name;
    std::string lastname;
};

void addUser(const Key &key, const Value &value);

Value getUser(const Key &key);

}
}
