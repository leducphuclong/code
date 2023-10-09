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
    string s;   cin >> s;

    lo len = s.size();
    lo cnt_A = 0;
    for (auto c : s)
        if (c == 'A')
            cnt_A++;

    bool double_B = false;
    for (lo i = 0; i < len-1; ++i)
        if (s[i] == 'B' && s[i+1] == 'B')
            double_B = true;
    
    if (s[0] == 'B' || s[len-1] == 'B' || double_B) {
        cout << cnt_A << nln;
        return;
    }

    vector<lo> grp;
    lo cur = 0;
    for (auto c : s)
        if (c == 'A') {
            cur++;
        } else {
            if (cur != 0) {
                grp.push_back(cur);
                cur = 0;
            }
        }
    if (cur)
        grp.push_back(cur);
    
    cout << accumulate(grp.begin(), grp.end(), 0) - *min_element(grp.begin(), grp.end()) << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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