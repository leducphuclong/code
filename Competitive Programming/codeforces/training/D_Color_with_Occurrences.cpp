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
vector<pair<lo, lo>> ans;
bool ok = true;
// End of global variable declaration.

void precompute() {
}

void Find(lo a, lo b, string s, vector<string> ss) {
    lo mx = 0, id = -1, pos = -1;
    for (lo p = a; p <= b; ++p)
        for (lo i = 0; i < ss.size(); ++i) {
            if (p+ss[i].size() > s.size() || p+ss[i].size() <= b) continue;
            string tmp = s.substr(p, ss[i].size());
            if (tmp == ss[i] && p+ss[i].size() > mx) {
                mx = p+ss[i].size();
                id = i;
                pos = p;
            }
        }

    if (b == s.size())
        return;
    if (id == -1) {
        ok = false;
        return;
    } else {
        ans.push_back({id, pos});
        Find(0, mx, s, ss);
    }

}


void solve() {
    string s;   cin >> s;
    lo n;   cin >> n;
    vector<string> ss(n);
    for (auto &v : ss)
        cin >> v;  


    ok = true;
    ans.clear();
    Find(0, 0, s, ss);

    if (!ok) {
        cout << -1 << nln;
        return;
    } else {
        cout << ans.size() << nln;
        for (auto v : ans)
            cout << v.first+1 << ' ' << v.second+1 << nln;
    }
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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