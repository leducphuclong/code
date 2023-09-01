// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

void solve() {
    // Input
    lo n, m;
    cin >> n >> m;
    // Init
    set<string> cache;
    lo idx = 1;
    map<string, string> dmn_sever, dmn_cache;
    map<string, lo> idx_cache;
    // Query
    cin.ignore();

    for (lo i = 1; i <= n; ++i) {
        cout << "i: " << i << nln;
        lo qr;
        cin >> qr;
        cin.ignore();
        string str, dm = "", ip = "";
        getline(cin, str, nln);
        lo vt = 0;
        for (lo i = 0; i < str.size(); ++i)
            if (str[i] == ' ') {
                vt = i;
                break;
            }
            else dm += str[i];
        if (qr == 1)
            for (lo i = vt+1; i < str.size(); ++i)
                ip += str[i];
        // Solve
        if (qr == 1) {
            dmn_sever[dm] = ip;
        } else {
            if (idx_cache[] != 0) {
                if (dmn_sever[dm] != dmn_sever[dm]) {
                    cout << "Warning: Possible DNS Poisoning detected!" << nln;
                    return;
                } else {
                }
            } else {

            }
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
  return 0;
}
