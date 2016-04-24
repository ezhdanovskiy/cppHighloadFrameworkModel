#pragma once

#include <SwipeDefines.h>
#include <User.h>

#include "SwipeStorage.h"

namespace Swipe {

class Impl {
public:
    TUserId addUser(const std::string &name, const std::string &lastname, const std::string &email);

    Model::User getUser(const TUserId &userId);

    void addFollower(const TUserId &userId, const TUserId &followerId);

    void addFollowers(const TUserId &userId, const TUserIds &followerIds);

    TUserIdsSet getFollowerIds(const TUserId &userId);

    void addPost(TUserId ownerId, const std::string &text, PostType postType, const TUserIds &participantIds = TUserIds());

private:
    MainStorage storage;
};

} // namespace Swipe
