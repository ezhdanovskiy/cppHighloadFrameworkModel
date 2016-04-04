#include <User.h>
#include <SwipeStorage.h>

#include <gtest/gtest.h>

TEST(ModelUserTest, ConstructorOfNotExistentUser) {
    Model::User user(1);
    EXPECT_EQ(1, user.getId());
    EXPECT_EQ("", user.getName());
    EXPECT_EQ("", user.getLastname());
}

TEST(ModelUserTest, ConstructorOfExistentUser) {
    Swipe::Storage::add(1, {1, "John", "Smith"});
    Model::User user(1);
    EXPECT_EQ(1, user.getId());
    EXPECT_EQ("John", user.getName());
    EXPECT_EQ("Smith", user.getLastname());
}

TEST(ModelUserTest, Setters) {
    Model::User user(10);
    EXPECT_EQ(10, user.getId());
    EXPECT_EQ("", user.getName());
    EXPECT_EQ("", user.getLastname());

    user.setId(11);
    EXPECT_EQ(11, user.getId());

    user.setName("John");
    EXPECT_EQ("John", user.getName());

    user.setLastname("Smith");
    EXPECT_EQ("Smith", user.getLastname());
}
