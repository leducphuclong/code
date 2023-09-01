// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

void precompute() {
}

void solve() {
    lo n;
    cin >> n;
    vector<lo> dgt;
    while (n > 0) {
        dgt.push_back(n%9);
        n /= 9;
    }
    while (!dgt.empty()) {
        cout << ((dgt.back() < 4) ? dgt.back() : dgt.back()+1);
        dgt.pop_back();
    }
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
  return 0;
}
