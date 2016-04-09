#include <UserStorage.h>

#include <gtest/gtest.h>

TEST(UserStorage, SimpleAddAndGet) {
    Storage::User::add({"John", "Smith"});
    auto user = Storage::User::get(1);

    EXPECT_EQ(1, user.id);
    EXPECT_EQ("John", user.name);
    EXPECT_EQ("Smith", user.lastname);
}
