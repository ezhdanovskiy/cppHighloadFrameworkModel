#include "SwipeImpl.h"

#include <gtest/gtest.h>
#include <memory>

struct SwipeServerTest : public ::testing::Test {
    void SetUp() { }

    void TearDown() { }
};

TEST_F(SwipeServerTest, User) {
    auto contactsStorage = std::make_shared<Storage::Contacts2>();
    auto eventsStorage = std::make_shared<Storage::Events>();
    Swipe::Impl impl(contactsStorage.get(), eventsStorage.get());

    auto userId1 = impl.addUser("John", "Smith", "J.Smith@ya.ru");

    auto user1 = impl.getUser(userId1);
    EXPECT_EQ(userId1, user1.getId());
    EXPECT_EQ("John", user1.getName());
    EXPECT_EQ("Smith", user1.getLastname());
    EXPECT_EQ("J.Smith@ya.ru", user1.getEmail());
}

TEST_F(SwipeServerTest, UserSubscription) {
    auto contactsStorage = std::make_shared<Storage::Contacts2>();
    auto eventsStorage = std::make_shared<Storage::Events>();
    Swipe::Impl impl(contactsStorage.get(), eventsStorage.get());

    auto userId1 = impl.addUser("John", "Smith", "J.Smith@ya.ru");
    auto userId2 = impl.addUser("George", "Washington", "G.Washington@ya.ru");
    auto userId3 = impl.addUser("Nicolas", "Cage", "N.Cage@ya.ru");
    auto userId4 = impl.addUser("Emma", "Watson", "E.Watson@ya.ru");

    impl.addFollower(userId1, userId2);
    impl.addFollowers(userId1, {userId3, userId4});

    auto followerIds = impl.getFollowerIds(userId1);
    EXPECT_EQ(3, followerIds.size());
    EXPECT_EQ(0, followerIds.count(userId1));
    EXPECT_EQ(1, followerIds.count(userId2));
    EXPECT_EQ(1, followerIds.count(userId3));
    EXPECT_EQ(1, followerIds.count(userId4));
}
