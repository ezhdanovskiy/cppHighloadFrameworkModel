#include <iostream>
#include <memory>

#include <UserStorage.h>
#include <User.h>
#include <Event.h>
#include <Subscriptions.h>
#include "SwipeImpl.h"

using namespace std;

int main() {
    auto contactsStorage = std::make_shared<Storage::Contacts2>();
    auto eventsStorage = std::make_shared<Storage::Events>();
    Swipe::Impl impl(contactsStorage.get(), eventsStorage.get());

    auto userId1 = impl.addUser("John", "Smith", "J.Smith@ya.ru");
    auto userId2 = impl.addUser("George", "Washington", "G.Washington@ya.ru");
    auto userId3 = impl.addUser("Nicolas", "Cage", "N.Cage@ya.ru");

    impl.subscribe(userId1, userId2);
    impl.subscribe(userId1, userId3);

    impl.addEvent(Swipe::Event::Type::publicEv, userId1, "Event1");
    return 0;
}
