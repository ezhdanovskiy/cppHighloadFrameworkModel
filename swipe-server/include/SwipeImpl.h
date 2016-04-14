#ifndef CPPSWIPE_SWIPEIMPL_H
#define CPPSWIPE_SWIPEIMPL_H

#include <string>

#include "User.h"
#include "UserStorage.h"
#include "ContactsStorage.h"
#include "Event.h"
#include "EventStorage.h"

namespace Swipe {

class Impl {
public:
    Impl(Storage::Contacts2 *contacts, Storage::Events *events) : contactsStorage(contacts), eventsStorage(events) { }

    Model::User::TUserId addUser(const std::string &name, const std::string &lastname, const std::string &email);

    void subscribe(const Model::User::TUserId &userId, const Model::User::TUserId &followerId);

    void addEvent(Event::Type eventType, Model::User::TUserId ownerId, const std::string &text);

private:
    Storage::Contacts2 *contactsStorage;
    Storage::Events *eventsStorage;
};

}

#endif //CPPSWIPE_SWIPEIMPL_H
