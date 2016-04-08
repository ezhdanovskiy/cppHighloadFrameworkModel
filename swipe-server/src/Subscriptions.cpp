#include "Subscriptions.h"

#include <iostream>

using namespace std;

void Swipe::Subscription::subscribe(const Model::User &user, const Model::User &follower) {
    cout << "Now " << follower.getName() << " follow to " << user.getName() << "." << endl;
}
