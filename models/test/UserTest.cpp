#include <User.h>
#include <UserStorage.h>

#include <gtest/gtest.h>

struct ModelUserTest : public ::testing::Test {
    Model::User::TUserId firstNotExistentUserId = 1;

    void SetUp() {
        firstNotExistentUserId = Storage::User::add({"John", "Smith"});
        firstNotExistentUserId++;
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
