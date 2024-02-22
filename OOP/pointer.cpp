#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    // p1, p2 are pointers that point to the address of x, y
    cout << "See Addresses: " << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Address that p1 point to: " << p1 << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Address that p2 point to: " << p2 << endl;
    // these pointers work like references
    cout << "Value of x: " << x << ' ' << *p1 << endl;
    cout << "Value of y: " << y << ' ' << *p2 << endl;
    *p1 = 100, *p2 = 101;
    cout << "After changing value at the address that two pointers are pointing to: " << endl;
    cout << "Value of x: " << x << ' ' << *p1 << endl;
    cout << "Value of y: " << y << ' ' << *p2 << endl;
    return 0;
}