#include "SwipeImpl.h"

#include <Logger.h>

namespace Swipe {

Model::User::TUserId Impl::addUser(const std::string &name, const std::string &lastname, const std::string &email) {
    return Storage::User::add({name, lastname, email});
}

void Impl::subscribe(const Model::User::TUserId &userId, const Model::User::TUserId &followerId) {
    contactsStorage->addFollower(userId, followerId);
}
void Impl::addEvent(Event::Type eventType, Model::User::TUserId ownerId, const std::string &text) {
    auto eventId = eventsStorage->add({eventType, ownerId, text});
    auto followers = contactsStorage->getFollowers(ownerId);
    LOG("followers.size=" << followers.size())
    switch (eventType) {
        case Event::Type::publicEv: {
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

}
