#include "ContactsStorage.h"
#include <Logger.h>

namespace Storage {

void Contacts::addFollower(TContactId userId, TContactId followerId) {
    storage[userId].insert(followerId);
    invertedIndex[followerId].insert(userId);
}

void Contacts::addFollowers(TContactId userId, const TContactIds &followerIds) {
    storage[userId].insert(followerIds.begin(), followerIds.end());
    for (const TContactId &followerId : followerIds) {
        LOG("Storage::Contacts::addFollowers(" << userId << ", " << followerId << ")");
        invertedIndex[followerId].insert(userId);
    }
}

} // namespace Storage
