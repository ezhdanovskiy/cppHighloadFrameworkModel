#pragma once

#include <inttypes.h>

namespace Storage {
namespace Contacts {

typedef uint64_t TContactId;

void addFollower(TContactId userId, TContactId followerId);

}
}
