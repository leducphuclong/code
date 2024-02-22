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
    lo n, m;    cin >> n >> m;
    vector<pair<lo, string>> p(n);
    for (auto &v : p)
        cin >> v.first >> v.second;
    set<string> ans;
    for (lo i = 0; i <= n; ++i) {
        bool chk = true;
        vector<char> nrm(m, '.');
        for (int j = 0; j < n; ++j)
            if (j != i)
                for (int k = p[j].first-1; k <= p[j].first-1+p[j].second.size()-1; ++k)
                    if (nrm[k] == p[j].second[k-p[j].first+1] || nrm[k] == '.')
                        nrm[k] = p[j].second[k-p[j].first+1];
                    else
                        chk = false;
        string res = "";
        for (auto c : nrm) {
            res += c;
            if (c == '.')
                chk = false;
        }
        if (chk)
            ans.insert(res);
    }
    
    if (ans.size() == 1)
        cout << *ans.begin() << nln;
    else if (ans.size() > 1)
        cout << -2  << nln;
    else
        cout << -1 << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}