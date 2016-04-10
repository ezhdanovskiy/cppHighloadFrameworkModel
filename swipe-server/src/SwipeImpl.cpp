#include "SwipeImpl.h"

namespace Swipe {

Model::User::TUserId Impl::addUser(const std::string &name, const std::string &lastname, const std::string &email) {
    return usersStorage->add({name, lastname, email});
}

void Impl::subscribe(const Model::User::TUserId &userId, const Model::User::TUserId &followerId) {
    contactsStorage->addFollower(userId, followerId);
}
void Impl::addEvent(Event::Type eventType, Model::User::TUserId ownerId, const std::string &text) {
    eventsStorage->add({eventType, ownerId, text});
}

}
