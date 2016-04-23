#include "SwipeImpl.h"

#include <UserStorage.h>

namespace Swipe {

TUserId Impl::addUser(const std::string &name, const std::string &lastname, const std::string &email) {
    return Storage::User::add({name, lastname, email});
}

Model::User Impl::getUser(const TUserId &userId) {
    auto dbUser = Storage::User::get(userId);
    return Model::User(dbUser.id, dbUser.name, dbUser.lastname, dbUser.email);
}

void Impl::addFollower(const TUserId &userId, const TUserId &followerId) {
    contactsStorage->addFollower(userId, followerId);
}

void Impl::addFollowers(const TUserId &userId, const TUserIds &followerIds) {
    Storage::Contacts2::TContactIds contactIds(followerIds.begin(), followerIds.end());
    contactsStorage->addFollowers(userId, contactIds);
}

TUserIdsSet Impl::getFollowerIds(const TUserId &userId) {
    auto contactIds = contactsStorage->getFollowers(userId);
    return TUserIdsSet(contactIds.begin(), contactIds.end());
}

void Impl::addEvent(TUserId ownerId, const std::string &text, Event::Type eventType, const TUserIds &participantIds) {
    auto eventId = eventsStorage->add({eventType, ownerId, text});
    switch (eventType) {
        case Event::Type::open: {
            auto followers = contactsStorage->getFollowers(ownerId);
            for (const auto &follower : followers) {
                LOG("Notify user(" << follower << ") about event{" << eventId << ", '" << text << "'}")
            }
            break;
        }
        case Event::Type::friendsOnly: {
            auto followers = contactsStorage->getFollowers(ownerId);
            auto followings = contactsStorage->getFollowings(ownerId);
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
