#pragma once

#include <UserStorage.h>
#include <ContactsStorage.h>
#include <PostStorage.h>

namespace Swipe {

class MainStorage {
    Storage::Users &users;
    Storage::Contacts contacts;
    Storage::Posts posts;
public:
    MainStorage() : users(Storage::Users::getInstance()) { }

    Storage::Users &getUsers() { return users; };

    Storage::Contacts &getContacts() { return contacts; };

    Storage::Posts &getPosts() { return posts; };
};

} // namespace Swipe
