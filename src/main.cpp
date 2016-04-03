#include <iostream>

#include <User.h>
#include <SwipeStorage.h>

using namespace std;

int main() {
    Swipe::Storage::add(1, {1, "John", "Smith"});
    User user(1);
    cout << "Hello, World! I am " << user.getName() << "!" << endl;
    return 0;
}