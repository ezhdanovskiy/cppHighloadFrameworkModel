#include "SwipeImpl.h"

#include <UserStorage.h>

namespace Swipe {

TUserId Impl::addUser(const std::string &name, const std::string &lastname, const std::string &email) {
    return storage.getUsers().add({name, lastname, email});
}

Model::User Impl::getUser(const TUserId &userId) {
    auto dbUser = storage.getUsers().get(userId);
    return Model::User(dbUser.id, dbUser.name, dbUser.lastname, dbUser.email);
}

void Impl::addFollower(const TUserId &userId, const TUserId &followerId) {
    storage.getContacts().addFollower(userId, followerId);
}

void Impl::addFollowers(const TUserId &userId, const TUserIds &followerIds) {
    Storage::Contacts::TContactIds contactIds(followerIds.begin(), followerIds.end());
    storage.getContacts().addFollowers(userId, contactIds);
}

TUserIdsSet Impl::getFollowerIds(const TUserId &userId) {
    auto contactIds = storage.getContacts().getFollowers(userId);
    return TUserIdsSet(contactIds.begin(), contactIds.end());
}

void Impl::addPost(TUserId ownerId, const std::string &text, PostType postType, const TUserIds &participantIds) {
    auto postId = storage.getPosts().add({postType, ownerId, text});
    switch (postType) {
        case PostType::open: {
            auto followers = storage.getContacts().getFollowers(ownerId);
            for (const auto &follower : followers) {
                LOG("Notify user(" << follower << ") about post{" << postId << ", '" << text << "'}")
            }
            break;
        }
        case PostType::friendsOnly: {
            auto followers = storage.getContacts().getFollowers(ownerId);
            auto followings = storage.getContacts().getFollowings(ownerId);
            for (const auto &follower : followers) {
                if (followings.count(follower)) {
                    LOG("Notify user(" << follower << ") about post{" << postId << ", '" << text << "'}")
                }
            }
            break;
        }
        case PostType::group: {
            for (const auto &participantId : participantIds) {
                LOG("Notify user(" << participantId << ") about post{" << postId << ", '" << text << "'}")
            }
            break;
        }
    }
}

} // namespace Swipe
