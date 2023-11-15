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
const lo N = (lo)2e18;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<string> power_of_2;
// End of global variable declaration.

void precompute() {
    for (lo i = 1; i <= N; i *= 2)
        power_of_2.push_back(to_string(i));
}

lo distance(string n, string s) {
    lo i = 0, j = 0;
    lo ln = n.size(), ls = s.size();
    lo taken = 0;
    while (i < ln && j < ls) {
        if (n[i] == s[j]) {
            taken++;
            ++j;
        }
        ++i;
    }
    // ln - taken : number of characters we have to delete from string n
    // s - taken : number of characters we have to add to string n
    return ln-taken + ls-taken;
}

void solve() {
    string n;
    cin >> n;
    lo ans = n.size()+1;
    for (auto s : power_of_2)
        ans = min(ans, distance(n, s));
    cout << ans << endl;
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