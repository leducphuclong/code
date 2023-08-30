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

void solve() {
    lo n, k;
    cin >> n >> k;
    cin.ignore();
    string str;
    getline(cin, str, nln);
    if (k % 2 == 0) {
        sort(str.begin(), str.end());
        cout << str << nln;
        return;
    }
    string odd = "", eve = "";
    for (lo i = 0; i < static_cast<lo>(str.size()); ++i)
        if (i % 2)
            odd += str[i];
        else
            eve += str[i];

    sort(odd.begin(), odd.end());
    sort(eve.begin(), eve.end());


    string ans = "";
    lo io = 0, ie = 0;
    for (lo i = 0; i < static_cast<lo>(str.size()); ++i)
        if (i % 2)
            ans += odd[io], io++;
        else
            ans += eve[ie], ie++;

    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
