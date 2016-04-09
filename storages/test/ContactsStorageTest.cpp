#include <ContactsStorage.h>

#include <gtest/gtest.h>

TEST(ContactsStorage, getFollowers) {
    Storage::Contacts::TContactId userId = 1;
    Storage::Contacts::TContactId followerId1 = 2;
    Storage::Contacts::TContactId followerId2 = 3;

    Storage::Contacts::addFollower(userId, followerId1);
    Storage::Contacts::addFollower(userId, followerId2);
    auto followers = Storage::Contacts::getFollowers(userId);

    EXPECT_EQ(2, followers.size());
    EXPECT_TRUE(followers.find(followerId1) != followers.end());
    EXPECT_TRUE(followers.find(followerId2) != followers.end());
}

TEST(ContactsStorage, getFollowings) {
    Storage::Contacts::TContactId userId1 = 1;
    Storage::Contacts::TContactId userId2 = 2;
    Storage::Contacts::TContactId followerId = 3;

    Storage::Contacts::addFollower(userId1, followerId);
    Storage::Contacts::addFollower(userId2, followerId);
    auto followers = Storage::Contacts::getFollowings(followerId);

    EXPECT_EQ(2, followers.size());
    EXPECT_TRUE(followers.find(userId1) != followers.end());
    EXPECT_TRUE(followers.find(userId2) != followers.end());
}
