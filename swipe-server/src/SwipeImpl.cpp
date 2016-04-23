#include "SwipeImpl.h"

#include <Logger.h>

namespace Swipe {

TUserId Impl::addUser(const std::string &name, const std::string &lastname, const std::string &email) {
    return Storage::User::add({name, lastname, email});
}

void Impl::addFollower(const TUserId &userId, const TUserId &followerId) {
    contactsStorage->addFollower(userId, followerId);
}

void Impl::addFollowers(const TUserId &userId, const TUserIds &followerIds) {
    Storage::Contacts2::TContactIds contactIds(followerIds.begin(), followerIds.end());
    contactsStorage->addFollowers(userId, contactIds);
}

void Impl::addEvent(Event::Type eventType, TUserId ownerId, const std::string &text) {
    auto eventId = eventsStorage->add({eventType, ownerId, text});
    auto followers = contactsStorage->getFollowers(ownerId);
    LOG("followers.size=" << followers.size())
    switch (eventType) {
        case Event::Type::open: {
            for (const auto &follower : followers) {
                LOG("Notify user(" << follower << ") about event{" << eventId << ", '" << text << "'}")
            }
            break;
        }
        case Event::Type::friendsOnly: {
            break;
        }
        case Event::Type::group: {
            break;
        }
        default: {
            break;
        }
    }
}

} // namespace Swipe
