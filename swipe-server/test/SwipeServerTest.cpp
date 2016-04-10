#include "SwipeImpl.h"

#include <gtest/gtest.h>
#include <memory>

struct SwipeServerLogicTest : public ::testing::Test {
    void SetUp() { }

    void TearDown() { }
};

TEST_F(SwipeServerLogicTest, UserSubscription) {
    Storage::Users usersStorage = Storage::Users::getInstance();
    auto contactsStorage = std::make_shared<Storage::Contacts2>();
    auto eventsStorage = std::make_shared<Storage::Events>();
    Swipe::Impl impl(&usersStorage, contactsStorage.get(), eventsStorage.get());

    auto userId1 = impl.addUser("John", "Smith", "J.Smith@ya.ru");
    auto userId2 = impl.addUser("George", "Washington", "G.Washington@ya.ru");
    auto userId3 = impl.addUser("Nicolas", "Cage", "N.Cage@ya.ru");

    impl.subscribe(userId1, userId2);
    impl.subscribe(userId1, userId3);

    impl.addEvent(Swipe::Event::Type::publicEv, userId1, "Event1");
}
