#include <gtest/gtest.h>

#include <User.h>
#include <UserStorage.h>

struct ModelUserTest : public ::testing::Test {

    void SetUp() {
    };

    void TearDown() {};

    static void TearDownTestCase() {
    }

    static void SetUpTestCase() {
        Storage::Users::getInstance().add({"John", "Smith", "J.Smith@ya.ru"});
    }
};

TEST_F(ModelUserTest, ConstructorOfNotExistentUser) {
    Model::User user(15);
    EXPECT_EQ(15, user.getId());
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
    Model::User user(23);
    EXPECT_EQ(23, user.getId());
    EXPECT_EQ("", user.getName());
    EXPECT_EQ("", user.getLastname());

    user.setId(23+1);
    EXPECT_EQ(23+1, user.getId());

    user.setName("John");
    EXPECT_EQ("John", user.getName());

    user.setLastname("Smith");
    EXPECT_EQ("Smith", user.getLastname());
}
