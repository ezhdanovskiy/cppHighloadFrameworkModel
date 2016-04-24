#pragma once

#include <set>
#include <map>

#include <SystemDefines.h>
#include <Logger.h>

namespace Storage {

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
            LOG("Storage::Contacts::addFollowers(" << userId << ", " << followerId << ")");
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

} // namespace Storage
