#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int x = 5;
    cout << "Address of variable x: " << &x << endl;
    int &y = x;
    cout << "Address of reference variable y: " << &y << endl;
    // You can see x and y have the same address in the memory.
    y++;
    cout << x << ' ' << y << endl;
    x++;
    cout << x << ' ' << y << endl;
    // When I try to change the value of one of the two variables, the remaining variable
    // also changes along with it.
    return 0;
}