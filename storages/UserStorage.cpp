#include "UserStorage.h"

#include <Logger.h>

namespace Storage {
namespace User {

  class Users {
  public:

      User::Key add(const User::Value &value) {
          User::Key key = storage.size() + 1;
          storage[key] = value;
          LOG("Storage::Users::add(" << key << ", " << value.name << ", " << value.lastname << ", " << value.email << ")")
          return key;
      };

      User::Value get(const User::Key &key) {
          std::cout << "Storage::Users::add(" << key << ", " << storage[key].name << ", " << storage[key].lastname << ", " << storage[key].email << ")" << std::endl;
          return storage[key].setId(key);
      };

  private:
      std::map<User::Key, User::Value> storage;

  // singleton ------------------------------
      Users() { };
  public:
      static Users &getInstance() {
          static Users instance;
          return instance;
      }

  };

Value get(const Key &key) {
    return Users::getInstance().get(key);
}

Key add(const Value &value) {
    Users::getInstance().add(value);
}

}
}
