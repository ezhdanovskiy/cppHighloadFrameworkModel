#include "Subscriptions.h"

#include <ContactsStorage.h>

#include <iostream>

using namespace std;

void Swipe::Subscription::subscribe(const Model::User &user, const Model::User &follower) {
    Storage::Contacts::addFollower(user.getId(), follower.getId());
    cout << "Now " << follower.getName() << " follow to " << user.getName() << "." << endl;
}
