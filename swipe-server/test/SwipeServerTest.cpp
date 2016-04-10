#include <UserStorage.h>
#include <Subscriptions.h>

#include <gtest/gtest.h>

struct SwipeServerLogicTest : public ::testing::Test {
    void SetUp() {
        Storage::User::add({"John", "Smith", "J.Smith@ya.ru"});
        Storage::User::add({"George", "Washington", "G.Washington@ya.ru"});
        Storage::User::add({"Nicolas", "Cage", "N.Cage@ya.ru"});
    };

    void TearDown() { };
};

TEST_F(SwipeServerLogicTest, UserSubscription) {
    Model::User user1(1);
    Model::User user2(2);
    Model::User user3(3);

    Swipe::Subscription::subscribe(user1, user2);
    Swipe::Subscription::subscribe(user1, user3);
}
