#ifndef CPPSWIPE_SWIPESTORAGE_H
#define CPPSWIPE_SWIPESTORAGE_H

#include <UserStorage.h>

namespace Storage2 {

class Contacts {
public:
    typedef System::TContactId TContactId;
    typedef std::set<TContactId> TContactIds;
    typedef std::map<TContactId, TContactIds> TContactMap;

    void addFollower(TContactId userId, TContactId followerId) {
        storage[userId].insert(followerId);
        invertedIndex[followerId].insert(userId);
    }

    void addFollowers(TContactId userId, const TContactIds &followerIds) {
        storage[userId].insert(followerIds.begin(), followerIds.end());
        for (const TContactId &followerId : followerIds) {
            LOG("Storage::Contacts2::addFollowers(" << userId << ", " << followerId << ")");
            invertedIndex[followerId].insert(userId);
        }
    }

    TContactIds getFollowers(TContactId userId) {
        return storage[userId];
    }

    TContactIds getFollowings(TContactId followerId) {
        return invertedIndex[followerId];
    }

private:
    TContactMap storage;
    TContactMap invertedIndex;
};

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
    Storage2::Contacts contacts;
    Storage2::Events events;
public:
    MainStorage() : users(Storage::Users::getInstance()) { }

    Storage::Users &getUsers() { return users; };

    Storage2::Contacts &getContacts() { return contacts; };

    Storage2::Events &getEvents() { return events; };
};

} // namespace Swipe

#endif //CPPSWIPE_SWIPESTORAGE_H
