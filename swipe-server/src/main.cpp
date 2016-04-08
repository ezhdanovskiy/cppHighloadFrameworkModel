#include <iostream>

#include <User.h>
#include <SwipeEvent.h>
#include <SwipeStorage.h>

using namespace std;

int main() {
    Swipe::Storage::addUser(1, {1, "John", "Smith"});
    Model::User user(1);
    cout << "Hello, World! I am " << user.getName() << "!" << endl;
    Model::SwipeEvent event(Model::SwipeEvent::Type::publicEv, 1);
    event.setText("Event01");
    cout << user.getName() << " creates event '" << event.getText() << "'." << endl;
    return 0;
}