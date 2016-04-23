#include "Event.h"

#include <iostream>

#include <EventStorage.h>

namespace Swipe {

Event::Event(Type type, const Model::User &owner, const std::string &text) : type(type), ownerId(owner.getId()), text(text) {
    LOG(owner.getName() << " creates event '" << text << "'.");
    id = Storage::Event::add({type, owner.getId(), text});
}

const std::string &Event::getText() const {
    return text;
}

void Event::setText(const std::string &text) {
    Event::text = text;
}

} // namespace Swipe
