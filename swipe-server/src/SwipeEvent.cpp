#include "SwipeEvent.h"

#include <iostream>

using namespace std;

Model::SwipeEvent::SwipeEvent(Type type, TEventId id, const Model::User &owner, const std::string &text) : type(type), id(id), ownerId(owner.getId()), text(text) {
    cout << owner.getName() << " creates chat '" << text << "'." << endl;
}

const std::string &Model::SwipeEvent::getText() const {
    return text;
}

void Model::SwipeEvent::setText(const std::string &text) {
    SwipeEvent::text = text;
}
