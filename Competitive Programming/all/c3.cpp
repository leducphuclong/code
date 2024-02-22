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
    lo n;
    cin >> n;
    if (n == 2) {
        cout << 2 << nln << 2 << ' ' << 1 << nln;
        return;
    }
    if (n == 3) {
        cout << 3 << nln << 3 << ' ' << 2 << ' ' << 1 << nln;
        return;
    }
    if (n == 4) {
        cout << 3 << nln << 4 << ' ' << 2 << ' ' << 1 << nln;
        return;
    }

    if (n % 2) {
        n--;
        vector<lo> ans = {1, 2, 4};
        while (ans.back()*2 < n)
            ans.push_back(ans.back()*2);
        for (lo i = ans.back()/2; i >= 1; --i)
            if (ans.back() % i == 0 && ans.back()+i <= n) {
                ans.push_back(ans.back()+i);
                break;
            }
        if (ans.back() != n)
            ans.push_back(n);
        ans.push_back(n+1);
        cout << ans.size() << nln;
        reverse(ans.begin(), ans.end());
        for (auto v : ans)
            cout << v << ' ';
        cout << nln;

    } else {
        vector<lo> ans = {1, 2, 3};
        while (ans.back()*2 < n)
            ans.push_back(ans.back()*2);

        for (lo i = ans.back()/2; i >= 1; --i)
            if (ans.back() % i == 0 && ans.back()+i <= n) {
                ans.push_back(ans.back()+i);
                break;
            }
         if (ans.back() != n)
            ans.push_back(n);

        cout << ans.size() << nln;
        reverse(ans.begin(), ans.end());
        for (auto v : ans)
            cout << v << ' ';
        cout << nln;
    }
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
