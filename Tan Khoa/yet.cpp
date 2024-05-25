// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<ll> coins = {1, 3, 6, 10, 15};
// End of global variable declaration.

void precompute() {
	
}

ll rec(ll n) {
	cout << "n: " << n << nln;
	if (n == 0)
		return 0;
	ll res = INT_MAX;
	for (auto v : coins)
		if (n >= v)
			res = min(res, n/v + rec(n % v));
	cout << "res: " << res << nln;
	getch();
	return res;
}


void solve() {
	reverse(coins.begin(), coins.end());
	ll n;	cin >> n;
	cout << rec(n);
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