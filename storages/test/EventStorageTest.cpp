#include <EventStorage.h>

#include <gtest/gtest.h>

TEST(EventStorageTest, SimpleAddAndGet) {
    int eventType = 1;
    Storage::TUserId ownerId = 1;
    std::string eventText = "Event1";

    auto eventId = Storage::Event::add({eventType, ownerId, eventText});
    auto event = Storage::Event::get(eventId);

    EXPECT_EQ(eventId, event.id);
    EXPECT_EQ(eventType, event.type);
    EXPECT_EQ(ownerId, event.ownerId);
    EXPECT_EQ(eventText, event.text);
}
