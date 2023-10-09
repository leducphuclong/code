#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef int64_t lo;


int main() {
    lo n2 = 76;
    for (lo i = 0; i < 76; ++i) {
        if (i < 10)
            cout << 0 << i;
        else
            cout << i;
        cout << "0000" << nln;
    } // -> total = 304000

    lo n3 = 601;
    for (lo i = 1000; i < 1601; ++i) {
        cout << i << "11"  << nln;
    } // -> total = 300500

    // -> sum = 604500
    return 0;
}