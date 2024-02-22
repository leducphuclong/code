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
	ll n;
	cin >> n;
	map<ll, ll> flag;
	while (n--) {
		ll left, right;	cin >> left >> right;
		flag[left]++, flag[right]--;
	}

	ll is_covered = 0, len = int(6e4);
	bool location[len+1];
	for (int i = 0; i <= len; ++i) {
		is_covered += flag[i];
		location[i] = (is_covered) ? (true) : (false);
	}

	ll max_len = 0, cur_len = 0;
	for (int i = 0; i <= len; ++i)
		if (location[i]) {
			cur_len++;
			if (cur_len > max_len)
				max_len = cur_len;
		} else {
			cur_len = 0;
		}
	cout << max_len;
}

int main(int argc, char* argv[]) {
	#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    //cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}