#include "ContactsStorage.h"

#include <map>

namespace Storage {
namespace Contacts {

class Storage {
public:
    typedef std::map<TContactId, std::set<TContactId> > TContactMap;

    static Storage &getInstance() {
        static Storage instance;
        return instance;
    }

    void addFollower(TContactId userId, TContactId followerId) {
        storage[userId].insert(followerId);
        invertedIndex[followerId].insert(userId);
    }

    TContactIds getFollowers(TContactId userId) {
        return storage[userId];
    }

private:
    TContactMap storage;
    TContactMap invertedIndex;
};

void addFollower(TContactId userId, TContactId followerId) {
    Storage::getInstance().addFollower(userId, followerId);
}

TContactIds getFollowers(TContactId userId) {
    return Storage::getInstance().getFollowers(userId);
}

}
}
