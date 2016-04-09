#include <iostream>

#include <UserStorage.h>
#include <User.h>
#include <SwipeEvent.h>
#include <Subscriptions.h>

using namespace std;

int main() {
    Storage::User::add({"John", "Smith"});
    Storage::User::add({"George", "Washington"});
    Storage::User::add({"Nicolas", "Cage"});

    Model::User user1(1);
    Model::User user2(2);
    Model::User user3(3);

    Swipe::Subscription::subscribe(user1, user2);
    Swipe::Subscription::subscribe(user1, user3);

    Model::SwipeEvent event(Model::SwipeEvent::Type::publicEv, 1, user1, "Event01");
    return 0;
}