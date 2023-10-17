#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

int main() {
    int x = 3, y = 4;
    int n = 6;
    cout << x << ' ' << y << nln;
    cout << y << ' ' << n-x+1 << nln;
    cout << n-x+1 << ' ' << n-y+1 << nln;
    cout << n-y+1 << ' ' << x << nln;
    return 0;
}