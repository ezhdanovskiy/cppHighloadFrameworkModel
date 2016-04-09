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

    void addFollowers(TContactId userId, const TContactIds& followerIds) {
        storage[userId].insert(followerIds.begin(), followerIds.end());
        for (const TContactId &followerId : followerIds) {
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

void addFollower(TContactId userId, TContactId followerId) {
    Storage::getInstance().addFollower(userId, followerId);
}

void addFollowers(TContactId userId, const TContactIds &followerIds) {
    Storage::getInstance().addFollowers(userId, followerIds);
}

TContactIds getFollowers(TContactId userId) {
    return Storage::getInstance().getFollowers(userId);
}

TContactIds getFollowings(TContactId followerId) {
    return Storage::getInstance().getFollowings(followerId);
}

}
}
