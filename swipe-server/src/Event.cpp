#include "Event.h"

#include <EventStorage.h>

#include <iostream>

using namespace std;

Swipe::Event::Event(Type type, const Model::User &owner, const std::string &text) : type(type), ownerId(owner.getId()), text(text) {
    cout << owner.getName() << " creates event '" << text << "'." << endl;
    id = Storage::Event::add({type, owner.getId(), text});
}

const std::string &Swipe::Event::getText() const {
    return text;
}

void Swipe::Event::setText(const std::string &text) {
    Event::text = text;
}
