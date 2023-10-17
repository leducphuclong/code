#include <iostream>

using namespace std;

int main() {
    int a, b;   cin >> a >> b;
    for (int x = 0; x <= 8; x += 2)
        cout << a << b << x << ' ';
    return 0;
}
