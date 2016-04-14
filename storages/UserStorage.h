#pragma once

#include <map>
#include <inttypes.h>
#include <string>
#include <iostream>

namespace Storage {

namespace User {
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

Value get(const Key &key);

Key add(const Value &value);

}
}
