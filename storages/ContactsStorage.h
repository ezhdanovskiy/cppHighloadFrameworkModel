#pragma once

#include <inttypes.h>
#include <set>
#include <map>

#include <SystemDefines.h>

namespace Storage {

class Contacts2 {
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

namespace Contacts {

typedef uint64_t TContactId;
typedef std::set<TContactId> TContactIds;

void addFollower(TContactId userId, TContactId followerId);

void addFollowers(TContactId userId, const TContactIds &followerIds);

TContactIds getFollowers(TContactId userId);

TContactIds getFollowings(TContactId followerId);

}
}
