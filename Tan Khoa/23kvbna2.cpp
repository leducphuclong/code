#include<iostream>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    if (a >= n)
        cout << abs(a-n-(b+n)) << '\n';
    else
        cout << b+a << '\n';
    return 0;
}