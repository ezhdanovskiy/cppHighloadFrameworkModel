#include <iostream>

#include "SwipeImpl.h"

int main() {
    Swipe::Impl impl;

    auto userId1 = impl.addUser("John", "Smith", "J.Smith@ya.ru");
    auto userId2 = impl.addUser("George", "Washington", "G.Washington@ya.ru");
    auto userId3 = impl.addUser("Nicolas", "Cage", "N.Cage@ya.ru");

    impl.addFollowers(userId1, {userId2, userId3});

    impl.addPost(userId1, "Post1", Swipe::PostType::open);
    return 0;
}
