// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

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
	ll n, l;		cin >> n >> l;
	vector<pair<ll, ll>> arr(n);
	for (auto &p : arr)
		cin >> p.first  >> p.second;
	sort(arr.begin(), arr.end(), 
		[](const pair<ll, ll>& a, const pair<ll, ll>& b) {
    		return a.second < b.second; // Compare the second value of each pair
		});
	
	multiset<> sav;
	for (ll i = 0; i < n; ++i) {
		for (ll j = i; j < n; ++j)
			
	}


}

int main(int argc, char* argv[]) {
	#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
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