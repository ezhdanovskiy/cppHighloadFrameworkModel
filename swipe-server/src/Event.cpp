#include "Event.h"

#include <iostream>

using namespace std;

Swipe::Event::Event(Type type, TEventId id, const Model::User &owner, const std::string &text) : type(type), id(id), ownerId(owner.getId()), text(text) {
    cout << owner.getName() << " creates chat '" << text << "'." << endl;
}

const std::string &Swipe::Event::getText() const {
    return text;
}

void Swipe::Event::setText(const std::string &text) {
    Event::text = text;
}
