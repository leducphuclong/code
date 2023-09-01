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
    string str;
    getline(cin, str, nln);
    vector<string> lnk, res;
    for (auto c : str)
        if (c == '/') {
            lnk.push_back("");
        } else {
            lnk.back() += c;
        }
    for (auto s : lnk)
        if (s != "")
            res.push_back(s);
    for (auto s : res)
        cout << "/" << s;
    if (res.empty())
        cout << "/" << nln;
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
  return 0;
}
