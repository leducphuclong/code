// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

bool isPrime(lo n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (lo i = 2; i <= round(sqrt(n)); ++i)
        if (n % i == 0)
            return false;
    return true;
}

void solve() {
    string str;
    getline(cin, str);

    lo n = (str[0]-'0')*10;
    for (lo i = 1; i < (lo)(str.size()); ++i) {
        lo t = n+(str[i]-'0');
        if (isPrime(t)) {
            cout << t << nln;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    cout << "He" << endl;
    return 0;
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    cin.ignore();
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Lng, Good for now !!" << nln;
    return 01;
}
