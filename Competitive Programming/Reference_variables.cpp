#include <iostream>

using namespace std;

int main() {
    int x = 1;
    int &y = x;
    cout << "&x: " << &x << '\n' ;
    return 0;
}