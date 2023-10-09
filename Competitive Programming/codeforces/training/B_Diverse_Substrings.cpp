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
    lo n;   cin >> n;
    string s;   cin >> s;
    lo ans = 0;
    for (lo i = 0; i < n; ++i) {
        lo max_fr = 0, distince = 0;
        map<lo, lo> fre;
        for (lo j = i; j < min(i+100, n); ++j) {
            lo x = s[j]-'0';
            fre[x]++;
            if (fre[x] == 11)
                break;
            if (fre[x] == 1)
                distince++;
            max_fr = max(max_fr, fre[x]);
            if (max_fr <= distince)
                ans++;
        }
    }
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