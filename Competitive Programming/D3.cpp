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
    lo cF = 0, cD = 0;
    bool chk = 1;
    for (auto ch : str) {
        if (ch == 'F') {
            cF = 1;
            cD = 0;
        } else if (ch == 'D') {
            if (cF == 0) {
                chk = 0;
                break;
            }
            ++cD;
            if (cD > 2) {
                chk = 0;
                break;
            }
        } else {
            chk = 0;
            break;
        }
    }
    if (!chk)
        cout << "No" << nln;
    else
        cout << "Yes" << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    cin.ignore();
    precompute();
    while (T--) {
        solve();
    }
  return 0;
}
