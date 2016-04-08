#include "SwipeEvent.h"

Model::SwipeEvent::SwipeEvent(Type type, TEventId id) : type(type), id(id) {
}

const std::string &Model::SwipeEvent::getText() const {
    return text;
}

void Model::SwipeEvent::setText(const std::string &text) {
    SwipeEvent::text = text;
}
