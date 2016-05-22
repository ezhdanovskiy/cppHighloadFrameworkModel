#include "UserStorage.h"
#include <Logger.h>

namespace Storage {

Users::Key Users::add(const Value &value) {
    Key key = storage.size() + 1;
    storage[key] = value;
    LOG("Storage::Users::add(" << key << ", " << value.name << ", " << value.lastname << ", " << value.email << ")");
    return key;
};

Users::Value Users::get(const Key &key) {
    LOG("Storage::Users::add(" << key << ", " << storage[key].name << ", " << storage[key].lastname << ", " << storage[key].email << ")");
    return storage[key].setId(key);
};

} // namespace Storage
