// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    string str;
    getline(cin, str);
    lo res = 0;
    if (str[0] == '_')
        res++;
    for (lo i = 1; i <= (lo)str.size(); ++i)
        if (str[i] == '_' && str[i-1] == '_')
            ++res;
    if (str[(lo)str.size()-1] == '_')
            ++res;
    if (str == "^")
        res++;
    cout << res << nln;
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
