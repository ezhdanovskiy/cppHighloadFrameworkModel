#include "UserStorage.h"

namespace Storage {
namespace User {

Users::Value get(const Users::Key &key) {
    Users::getInstance().get(key);
}

Users::Key add(const Users::Value &value) {
    Users::getInstance().add(value);
}

}
}
