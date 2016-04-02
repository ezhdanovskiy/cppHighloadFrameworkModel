#include <iostream>

#include "User.h"

using namespace std;

int main() {
    User user(1, "John", "Smith");
    cout << "Hello, World! I am " << user.getName() << "!" << endl;
    return 0;
}