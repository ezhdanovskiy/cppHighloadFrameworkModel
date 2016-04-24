#include <iostream>
#include <memory>

#include <UserStorage.h>
#include <User.h>
#include <Event.h>
#include "SwipeImpl.h"

int main() {
    Swipe::Impl impl;

    auto userId1 = impl.addUser("John", "Smith", "J.Smith@ya.ru");
    auto userId2 = impl.addUser("George", "Washington", "G.Washington@ya.ru");
    auto userId3 = impl.addUser("Nicolas", "Cage", "N.Cage@ya.ru");

    impl.addFollowers(userId1, {userId2, userId3});

    impl.addEvent(userId1, "Event1", Swipe::Event::Type::open);
    return 0;
}
