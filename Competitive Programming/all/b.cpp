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

bool check(string s1, string s2, char c) {
    lo z1 = 0, z2 = 0;
    for (lo i = 0; i < (lo)s1.size(); ++i) {
        if (s1[i] == c)
            z1 = i;
        if (s2[i] == c)
            z2 = i;
    }
    char rc;
    if (c == '0')
        rc = '1';
    else
        rc = '0';
    if ((z1 <= z2 && s2[z1+1] == rc && s1[z1] == s2[z1])
        || (z2 <= z1 && s1[z2+1] == rc && s1[z2] == s2[z2]))
        return true;
    return false;
}

void solve() {
    string s1, s2;
    getline(cin, s1, nln);
    getline(cin, s2, nln);

    if (check(s1, s2, '0')) {
        cout << "YES" << nln;
        return;
    }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    if (check(s1, s2, '1')) {
        cout << "YES" << nln;
        return;
    }

    cout << "NO" << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    cin.ignore();
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
