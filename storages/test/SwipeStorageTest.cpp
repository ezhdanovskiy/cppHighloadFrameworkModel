#include <SwipeStorage.h>

#include <gtest/gtest.h>

TEST(SwipeStorage, SimpleAddAndGet) {
    Swipe::Storage::addUser(1, {1, "John", "Smith"});
    auto user = Swipe::Storage::getUser(1);
    EXPECT_EQ(1, user.id);
    EXPECT_EQ("John", user.name);
    EXPECT_EQ("Smith", user.lastname);
}
