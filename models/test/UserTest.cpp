#include <User.h>
#include <SwipeStorage.h>

#include <gtest/gtest.h>

struct ModelUserTest : public ::testing::Test {
    Model::User::TUserId firstNotExistentUserId = 1;

    void SetUp() {
        Model::User::TUserId userId = firstNotExistentUserId;
        Swipe::Storage::addUser(userId, {userId, "John", "Smith"});
        ++userId;
        firstNotExistentUserId = userId;
    };

    void TearDown() {};
};

TEST_F(ModelUserTest, ConstructorOfNotExistentUser) {
    Model::User user(firstNotExistentUserId);
    EXPECT_EQ(firstNotExistentUserId, user.getId());
    EXPECT_EQ("", user.getName());
    EXPECT_EQ("", user.getLastname());
}

TEST_F(ModelUserTest, ConstructorOfExistentUser) {
    Swipe::Storage::addUser(1, {1, "John", "Smith"});
    Model::User user(1);
    EXPECT_EQ(1, user.getId());
    EXPECT_EQ("John", user.getName());
    EXPECT_EQ("Smith", user.getLastname());
}

TEST_F(ModelUserTest, Setters) {
    Model::User user(firstNotExistentUserId);
    EXPECT_EQ(firstNotExistentUserId, user.getId());
    EXPECT_EQ("", user.getName());
    EXPECT_EQ("", user.getLastname());

    user.setId(firstNotExistentUserId+1);
    EXPECT_EQ(firstNotExistentUserId+1, user.getId());

    user.setName("John");
    EXPECT_EQ("John", user.getName());

    user.setLastname("Smith");
    EXPECT_EQ("Smith", user.getLastname());
}
