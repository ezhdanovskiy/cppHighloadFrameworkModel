#include <iostream>

#include <User.h>
#include <SwipeStorage.h>

using namespace std;

int main() {
    Swipe::Storage::addUser(1, {1, "John", "Smith"});
    Model::User user(1);
    cout << "Hello, World! I am " << user.getName() << "!" << endl;
    return 0;
}