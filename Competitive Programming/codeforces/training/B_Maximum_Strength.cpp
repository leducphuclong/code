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
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    string n1, n2;  cin >> n1 >> n2;
    lo add = abs(lo(n1.size()-n2.size()));
    while (add--) {
        if (n1.size() < n2.size())
            n1 = '0'+n1;
        else
            n2 = '0'+n2;
    }
    lo i = 0, n = n1.size();
    lo ans = 0;
    while (i < n) {
        if (n1[i] == n2[i]) {
            i++;
        } else {
            ans = abs((n1[i]-'0')-(n2[i]-'0'));
            break;
        }
    }
    // cout << "i:  " << i << " -> " << n-i-1 << nln;
    if (i < n)
        ans += 9*(n-i-1);
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}