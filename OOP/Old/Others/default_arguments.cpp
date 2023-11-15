#include <iostream>

using namespace std;

void show(int x, int y = 1, int z = 2) {
    cout << x << ' ' << y << ' ' << z << endl;
}

int main() {
    // show(); // CE Error
    show(1); // 1 1 2
    show(1, 2); // 1 2 2
    show(1, 2, 3); // 1 2 3
    return 0;
}