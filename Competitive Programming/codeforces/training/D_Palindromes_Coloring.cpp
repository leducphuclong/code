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
    lo n, k;    cin >> n >> k;
    string str;         cin >> str;

    map<char, lo> cnt;
    for (auto c : str)
        cnt[c]++;

    lo ans = 0, cnt_pair = 0, cnt_odd = 0;
    for (auto &p : cnt) {
        cnt_pair += p.second/2;
        cnt_odd += p.second % 2;
    }
    
    ans += 2*(cnt_pair/k);
    cnt_odd += 2*(cnt_pair%k);
    ans += (cnt_odd >= k);

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