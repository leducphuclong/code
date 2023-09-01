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

bool check_prime(lo n) {
    if (n <= 2)
        return false;
    for (lo i = 2; i <= round(sqrt(n)); ++i)
        if (n % i == 0)
            return false;
    return true;
}

lo max_dvs(lo n) {
    lo ans = 1;
    for (lo i = 2; i <= round(sqrt(n)); ++i)
        if (n % i == 0) {
            lo d1 = i, d2 = n/i;
            if (d1 > ans && !check_prime(d1))
                ans = d1;
            if (d2 > ans && !check_prime(d2))
                ans = d2;
        }
    return ans;
}

void solve() {
    lo n;
    cin >> n;
    vector<lo> ans = {n};
    map<lo, lo> cnt;
    while (n > 1) {
        lo k = max_dvs(n);
        n -= k;
        cnt[k]++;
        if (cnt[k] > 2) {
            cout << "n: " << n << nln;
            cout << "k: " << k << nln;
            cout << cnt[k] << nln;
            cout << "Saiiiiiiiiiiiiiiiiiiiiii" << nln;
        }
        ans.push_back(n);
    }
    cout << ans.size() << nln;
    for (auto v : ans)
        cout << v << ' ';
    cout << nln;
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
