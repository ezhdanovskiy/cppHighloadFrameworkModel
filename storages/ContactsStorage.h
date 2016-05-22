#pragma once

#include <set>
#include <map>

#include <SystemDefines.h>

namespace Storage {

class Contacts {
public:
    typedef System::TContactId TContactId;
    typedef std::set<TContactId> TContactIds;
    typedef std::map<TContactId, TContactIds> TContactMap;

    void addFollower(TContactId userId, TContactId followerId);

    void addFollowers(TContactId userId, const TContactIds &followerIds);

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
