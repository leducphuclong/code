// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>
#include <conio.h>
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
    ll n;   cin >> n;
    vector<ll> x(n), a(n);
    for (int i = 1; i < n; ++i)
        cin >> x[i];
    
    a[0] = x[1]+1;

    for (int i = 1; i < n-1; ++i) {
        if (x[i] > x[i+1])
            a[i] = x[i];
        else if (x[i] == x[i+1]) {
            // cout << "this case!" << nln;
            a[i] = a[i-1] + x[i];
        }
        else
            a[i] = ceil((x[i+1] - x[i] + 1)/(double)a[i-1])*a[i-1] + x[i];
        // cout << "ai: " << a[i] << nln;
        // cout << a[i] % a[i-1] << nln;
        // getch();
    }
    a[n-1] = a[n-2] + x[n-1];

    cout << a[0] << ' ';

    for (int i = 1; i < n; ++i) {
        // cout << static_cast<double>(a[i] % a[i-1])   << " ";
        // cout << a[i] << " ~ " << a[i-1] << nln;
        // cout << getch();
        cout << a[i] << ' ';
    }
    cout << nln;

}

int main(int argc, char* argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}