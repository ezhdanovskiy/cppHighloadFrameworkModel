#include <gtest/gtest.h>

#include <PostStorage.h>

TEST(PostStorageTest, SimpleAddAndGet) {
    Storage::Posts posts;

    int postType = 1;
    System::TUserId ownerId = 1;
    std::string postText = "Post1";

    auto postId = posts.add({postType, ownerId, postText});
    auto post = posts.get(postId);

    EXPECT_EQ(postId, post.id);
    EXPECT_EQ(postType, post.type);
    EXPECT_EQ(ownerId, post.ownerId);
    EXPECT_EQ(postText, post.text);
}

TEST(PostStorageTest, Del) {
    Storage::Posts posts;

    int postType = 1;
    System::TUserId ownerId = 1;
    std::string postText = "Post1";

    auto postId = posts.add({postType, ownerId, postText});
    {
        auto post = posts.get(postId);
        EXPECT_EQ(postId, post.id);
        EXPECT_EQ(postType, post.type);
        EXPECT_EQ(ownerId, post.ownerId);
        EXPECT_EQ(postText, post.text);
    }

    EXPECT_TRUE(posts.del(postId));
    {
        auto post = posts.get(postId);
        EXPECT_NE(postId, post.id);
        EXPECT_NE(postType, post.type);
        EXPECT_NE(ownerId, post.ownerId);
        EXPECT_NE(postText, post.text);
    }

    EXPECT_FALSE(posts.del(postId));
}
