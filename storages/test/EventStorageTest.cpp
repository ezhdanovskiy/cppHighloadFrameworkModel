#include <gtest/gtest.h>

#include <EventStorage.h>

TEST(EventStorageTest, SimpleAddAndGet) {
    int eventType = 1;
    System::TUserId ownerId = 1;
    std::string eventText = "Event1";

    Storage::Events events;
    auto eventId = events.add({eventType, ownerId, eventText});
    auto event = events.get(eventId);

    EXPECT_EQ(eventId, event.id);
    EXPECT_EQ(eventType, event.type);
    EXPECT_EQ(ownerId, event.ownerId);
    EXPECT_EQ(eventText, event.text);
}
