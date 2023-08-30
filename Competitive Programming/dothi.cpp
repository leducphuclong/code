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
    lo xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    lo xab = xb-xa, yab = yb-ya;
    lo xbc = xc-xb, ybc = yc-yb;
    lo res = xab*ybc - xbc*yab;
    if (res == 0)
        cout << "TOWARDS" << nln;
    else if (res > 0)
            cout << "LEFT" << nln;
        else
            cout << "RIGHT" << nln;
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
