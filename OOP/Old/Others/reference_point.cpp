#include <iostream>

using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int x = 3, y = 5;
    swap(&x, &y);
    cout << x << ' ' << y << endl;
    return 0;
}