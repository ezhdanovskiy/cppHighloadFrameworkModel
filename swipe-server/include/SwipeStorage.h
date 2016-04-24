#ifndef CPPSWIPE_SWIPESTORAGE_H
#define CPPSWIPE_SWIPESTORAGE_H

#include <UserStorage.h>

namespace Storage2 {

class Events {
public:
    typedef System::TUserId Key;

    struct Value {
        Value() { }

        Value(int type, System::TUserId ownerId, const std::string &text) : type(type), ownerId(ownerId), text(text) { }

        Value &setId(Key id) {
            Value::id = id;
            return *this;
        }

        Key id = 0;
        int type;
        System::TUserId ownerId;
        std::string text;
    };

    Key add(const Value &value) {
        Key key = storage.size() + 1;
        storage[key] = value;
        LOG("Storage::Event::add(" << key << ", type=" << value.type << ", ownerId=" << value.ownerId << ", text='" << value.text << "')")
        return key;
    };

    Value get(const Key &key) {
        return storage[key].setId(key);
    };

private:
    std::map<Key, Value> storage;
};

} // namespace Storage2

namespace Swipe {

class MainStorage {
    Storage::Users &users;
    Storage::Contacts contacts;
    Storage2::Events events;
public:
    MainStorage() : users(Storage::Users::getInstance()) { }

    Storage::Users &getUsers() { return users; };

    Storage::Contacts &getContacts() { return contacts; };

    Storage2::Events &getEvents() { return events; };
};

} // namespace Swipe

#endif //CPPSWIPE_SWIPESTORAGE_H
