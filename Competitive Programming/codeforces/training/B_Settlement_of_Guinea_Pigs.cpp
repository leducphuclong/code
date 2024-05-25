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
    ll  n;  cin >> n;
    ll aviaries = 0, redundant = 0, pig = 0, max_redundant = 0,
    max_aviaries = 0;
    while (n--) {
        ll plan;    cin >> plan;
        // cout << "plan: " << plan << endl;
        if (plan == 1) {
            // cout << "pig: " << pig << nln;
            pig++;
            aviaries++;
            // cout << "aviaries: " << aviaries << nln;

            max_aviaries = max(max_aviaries, aviaries);
        } else {
            // cout << "pig: " << pig << nln;
            // ll gender1 = ceil(pig / 2.0), gender2 = pig - gender1;
            // cout << gender1 << ' ' << gender2 << nln;
            // ll old_aviaries = aviaries;
            aviaries = pig / 2;
            if (pig)
                aviaries++;
            // redundant = max_aviaries - aviaries;
        }

        // cout << "aviaries: " << aviaries << nln;
        // cout << "redundant: " << redundant << nln;
        // cout << nln;
    }

    cout << max_aviaries << nln;
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