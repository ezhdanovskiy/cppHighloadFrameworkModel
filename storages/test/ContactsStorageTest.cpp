#include <ContactsStorage.h>

#include <gtest/gtest.h>

TEST(ContactsStorage, SimpleAddAndGet) {
    Storage::Contacts::TContactId userId = 1;
    Storage::Contacts::TContactId followerId = 2;

    Storage::Contacts::addFollower(userId, followerId);
    auto followers = Storage::Contacts::getFollowers(userId);

    EXPECT_EQ(1, followers.size());
    EXPECT_TRUE(followers.find(followerId) != followers.end());
}
