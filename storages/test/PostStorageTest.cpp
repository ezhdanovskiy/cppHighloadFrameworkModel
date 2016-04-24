#include <gtest/gtest.h>

#include <PostStorage.h>

TEST(PostStorageTest, SimpleAddAndGet) {
    int postType = 1;
    System::TUserId ownerId = 1;
    std::string postText = "Post1";

    Storage::Posts posts;
    auto postId = posts.add({postType, ownerId, postText});
    auto post = posts.get(postId);

    EXPECT_EQ(postId, post.id);
    EXPECT_EQ(postType, post.type);
    EXPECT_EQ(ownerId, post.ownerId);
    EXPECT_EQ(postText, post.text);
}
