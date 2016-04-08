#include <iostream>

#include <UserStorage.h>
#include <User.h>
#include <SwipeEvent.h>
#include <Subscriptions.h>

using namespace std;

int main() {
    Storage::User::add(1, {1, "John", "Smith"});
    Storage::User::add(2, {2, "George", "Washington"});

    Model::User user1(1);
    Model::User user2(2);

    Swipe::Subscription::subscribe(user1, user2);

    Model::SwipeEvent event(Model::SwipeEvent::Type::publicEv, 1, user1, "Event01");
    return 0;
}