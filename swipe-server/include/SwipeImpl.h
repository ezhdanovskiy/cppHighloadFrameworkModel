#ifndef CPPSWIPE_SWIPEIMPL_H
#define CPPSWIPE_SWIPEIMPL_H

#include <string>

#include <SwipeDefines.h>
#include <ContactsStorage.h>
#include <EventStorage.h>

#include "SwipeStorage.h"

namespace Swipe {

class Impl {
public:
    TUserId addUser(const std::string &name, const std::string &lastname, const std::string &email);

    Model::User getUser(const TUserId &userId);

    void addFollower(const TUserId &userId, const TUserId &followerId);

    void addFollowers(const TUserId &userId, const TUserIds &followerIds);

    TUserIdsSet getFollowerIds(const TUserId &userId);

    void addEvent(TUserId ownerId, const std::string &text, EventType eventType, const TUserIds &participantIds = TUserIds());

private:
    MainStorage storage;
};

} // namespace Swipe

#endif //CPPSWIPE_SWIPEIMPL_H
