#ifndef CPPSWIPE_SWIPEIMPL_H
#define CPPSWIPE_SWIPEIMPL_H

#include <string>

#include <SwipeDefines.h>
#include <ContactsStorage.h>
#include <EventStorage.h>

#include "Event.h"

namespace Swipe {

class Impl {
public:
    Impl(Storage::Contacts2 *contacts, Storage::Events *events) : contactsStorage(contacts), eventsStorage(events) { }

    TUserId addUser(const std::string &name, const std::string &lastname, const std::string &email);

    Model::User getUser(const TUserId &userId);

    void addFollower(const TUserId &userId, const TUserId &followerId);

    void addFollowers(const TUserId &userId, const TUserIds &followerIds);

    TUserIdsSet getFollowerIds(const TUserId &userId);

    void addEvent(TUserId ownerId, const std::string &text, Event::Type eventType, const TUserIds &participantIds = TUserIds());

private:
    Storage::Contacts2 *contactsStorage;
    Storage::Events *eventsStorage;
};

} // namespace Swipe

#endif //CPPSWIPE_SWIPEIMPL_H
