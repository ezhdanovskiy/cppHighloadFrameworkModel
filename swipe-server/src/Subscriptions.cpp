#include "Subscriptions.h"

#include <ContactsStorage.h>
#include <Logger.h>

void Swipe::Subscription::subscribe(const Model::User &user, const Model::User &follower) {
    Storage::Contacts::addFollower(user.getId(), follower.getId());
    LOG("Now " << follower.getName() << " follow to " << user.getName() << ".");
}
