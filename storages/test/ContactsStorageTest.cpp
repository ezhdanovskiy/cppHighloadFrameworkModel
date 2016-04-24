#include <ContactsStorage.h>

#include <gtest/gtest.h>

using TContactId = Storage::Contacts::TContactId;
using TContactIds = Storage::Contacts::TContactIds;

TEST(ContactsStorageTest, getFollowers) {
    Storage::Contacts contacts;

    TContactId userId = 1;
    TContactId followerId1 = 2;
    TContactId followerId2 = 3;

    contacts.addFollower(userId, followerId1);
    contacts.addFollower(userId, followerId2);
    auto followers = contacts.getFollowers(userId);

    EXPECT_EQ(2, followers.size());
    EXPECT_TRUE(followers.find(followerId1) != followers.end());
    EXPECT_TRUE(followers.find(followerId2) != followers.end());
}

TEST(ContactsStorageTest, getFollowings) {
    Storage::Contacts contacts;

    TContactId userId1 = 1;
    TContactId userId2 = 2;
    TContactId followerId = 3;

    contacts.addFollower(userId1, followerId);
    contacts.addFollower(userId2, followerId);
    auto followers = contacts.getFollowings(followerId);

    EXPECT_EQ(2, followers.size());
    EXPECT_TRUE(followers.find(userId1) != followers.end());
    EXPECT_TRUE(followers.find(userId2) != followers.end());
}

TEST(ContactsStorageTest, addFollowers) {
    Storage::Contacts contacts;

    TContactId userId = 1;
    TContactIds followerIds = {2, 3, 4};

    contacts.addFollowers(userId, followerIds);
    auto followers = contacts.getFollowers(userId);

    EXPECT_EQ(3, followers.size());
    for (const auto &followerId : followerIds) {
        EXPECT_TRUE(followers.find(followerId) != followers.end());
    }
}
