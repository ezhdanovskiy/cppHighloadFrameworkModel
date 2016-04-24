#include "SwipeImpl.h"

#include <UserStorage.h>

namespace Swipe {

TUserId Impl::addUser(const std::string &name, const std::string &lastname, const std::string &email) {
    return storage.getUsers().add({name, lastname, email});
}

Model::User Impl::getUser(const TUserId &userId) {
    auto dbUser = storage.getUsers().get(userId);
    return Model::User(dbUser.id, dbUser.name, dbUser.lastname, dbUser.email);
}

void Impl::addFollower(const TUserId &userId, const TUserId &followerId) {
    storage.getContacts().addFollower(userId, followerId);
}

void Impl::addFollowers(const TUserId &userId, const TUserIds &followerIds) {
    Storage2::Contacts::TContactIds contactIds(followerIds.begin(), followerIds.end());
    storage.getContacts().addFollowers(userId, contactIds);
}

TUserIdsSet Impl::getFollowerIds(const TUserId &userId) {
    auto contactIds = storage.getContacts().getFollowers(userId);
    return TUserIdsSet(contactIds.begin(), contactIds.end());
}

void Impl::addEvent(TUserId ownerId, const std::string &text, Event::Type eventType, const TUserIds &participantIds) {
    auto eventId = storage.getEvents().add({eventType, ownerId, text});
    switch (eventType) {
        case Event::Type::open: {
            auto followers = storage.getContacts().getFollowers(ownerId);
            for (const auto &follower : followers) {
                LOG("Notify user(" << follower << ") about event{" << eventId << ", '" << text << "'}")
            }
            break;
        }
        case Event::Type::friendsOnly: {
            auto followers = storage.getContacts().getFollowers(ownerId);
            auto followings = storage.getContacts().getFollowings(ownerId);
            for (const auto &follower : followers) {
                if (followings.count(follower)) {
                    LOG("Notify user(" << follower << ") about event{" << eventId << ", '" << text << "'}")
                }
            }
            break;
        }
        case Event::Type::group: {
            for (const auto &participantId : participantIds) {
                LOG("Notify user(" << participantId << ") about event{" << eventId << ", '" << text << "'}")
            }
            break;
        }
    }
}

} // namespace Swipe
