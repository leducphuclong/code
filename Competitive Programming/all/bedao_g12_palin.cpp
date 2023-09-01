// Copyright (c) 2023, Le Duc Phuc Long
//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define lo int64_t
#define nln '\n'

const lo LS = 1e5+10, MOD = 1e9+7;

using std::cout, std::cin, std::string, std::map, std::vector;

map<char, int> cnt[LS]; lo fact[LS] = {1};

lo mod_inverse(lo A, lo M) {  // Checked
    lo x = 1, y = 0;
    if (M == 1)
        return 0;
    while (A > 1) {
        lo tA = A;
        A = M % A;
        lo tM = M;
        M = tA;

        lo tx = x;
        x = y - tM/tA*x;
        y = tx;
    }
    return (x+MOD)%MOD;
}

void solve() {
    // Input
    string str; cin >> str;
    // Initialize the cnt array
    cnt[1][str[0]]++;
    for (int i = 1; i < static_cast<int>(str.size()); ++i) {
        for (auto c = 'a'; c <= 'z'; ++c)
            cnt[i+1][c] = cnt[i][c];
        cnt[i+1][str[i]]++;
    }
    // Precompute the factorial array
    for (lo i = 1; i < LS; ++i)
        fact[i] = fact[i-1]*i%MOD;
    // Solve
    lo m;
    cin >> m;
    while (m--) {
        // Queries
        lo l, r;
        cin >> l >> r;
        // Count
        lo odd = 0, eve = 0;
        vector<lo> dup;
        for (auto c = 'a'; c <= 'z'; ++c) {
            lo qtt = cnt[r][c]-cnt[l-1][c];
            odd += qtt % 2;
            eve += qtt / 2;
            if (qtt/2 != 0)
                dup.push_back(qtt/2);
        }
        if (!odd)
            odd = 1;
        lo res = fact[eve]%MOD*odd%MOD;
        for (auto i : dup)
            res *= mod_inverse(fact[i], MOD), res %= MOD;
        // Output
        cout << res << nln;
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
