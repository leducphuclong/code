// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>
// #include <conio.h>

// Namespace
using namespace std;

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
    
}


void solve() {
    ll n, m;    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    ll left = 0, right = 0, ans = 0;
    while (left < n && right < m) {
        if (s1[left] == s2[right]) {
            left++, right++;
            ans++;
        } else {
            right++;
        }
    }

    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    #ifndef ONLINE_JUDGE
    //freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
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