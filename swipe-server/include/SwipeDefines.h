#pragma once

#include <vector>
#include <set>

#include <SystemDefines.h>

namespace Swipe {

typedef System::TUserId TUserId;
typedef std::vector<TUserId> TUserIds;
typedef std::set<TUserId> TUserIdsSet;

enum EventType {
    open, friendsOnly, group
};

} // namespace Swipe
