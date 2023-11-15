#include <iostream>

using namespace std;

const int &func() {
    static int x = 4;
    return x;
}

int main() {
    cout << func(); // output: 4
    // cout << func()++ -> Compiler Error
    return 0;
}