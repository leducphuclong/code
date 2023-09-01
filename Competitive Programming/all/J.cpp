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
const lo mod = 1e9+7;

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n, q;
    cin >> n >> q;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    // Build Prefix Sum
    vector<lo> psa = {0};
    for (auto v : arr)
        psa.push_back((psa.back()+v)%mod);

    vector<lo> pma = {0, arr[0]};
    for (lo i = 2; i <= n; ++i)
        pma.push_back((arr[i-1]*(psa[i-1]))%mod);

    vector<lo> S = {0};
    for (lo i = 1; i <= n; ++i)
        S.push_back((pma[i]+S.back()));

    // Process Query
    while (q--) {
        lo l, r;
        cin >> l >> r;
        if (l == r)
            cout << arr[l-1] << nln;
        else
            cout << ((S[r]-S[l]-((psa[r]-psa[l]+mod)*psa[l-1]%mod))+mod)%mod << nln;
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
