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

// End of global variable declaration.

void precompute() {
}

ll str2int(string s) {
	ll res = 0, n = s.size(), p = 1;
	reverse(s.begin(), s.end());
	for (ll i = 0; i < n; ++i)
		res += (s[i]-'0')*p, p *= 10;
	return res;
}

string int2str(ll n) {
	if (n == 0)
		return "0";
	string res = "";
	while (n > 0) {
		res += (n%10 + '0');
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

vector<ll> genPalin(ll n) {
	vector<ll> res;
	for (ll i = 0; i < n; ++i)
		for (ll j = 0; j < 10; ++j) {
			string left = int2str(i),
			right = left;
			reverse(right.begin(), right.end());
			string mid = int2str(j),
			palin = (left + mid + right);
			if (i)
				if (palin.back()-'0' % 2)
					res.push_back(str2int(palin));
			else
				if (j % 2)
					res.push_back(j);
			// cout << i << " ~ " << j << " : " << res.back() << nln;
			// getch();

		}
	res.push_back(11);
	return res;
}

ll fastmul(ll a, ll b, ll p) {
	ll res = 0;
	a %= p;
	while (b) {
		if (b & 1)
			res += a, res %= p;
		a += a, a %= p;
		b >>= 1;
	}
	return res;
}

ll fastpow(ll a, ll n, ll p) {
	ll res = 1;
	a %= p;
	while (n) {
		if (n & 1)
			res = fastmul(res, a, p);
		a = fastmul(a, a, p);
		n >>= 1;
	}
	return res;
}

bool single_test(ll a, ll n) {
    ll exp = n - 1;
    while (!(exp & 1))
        exp >>= 1;
    ll tmp = fastpow(a, exp, n);
    if (tmp == 1)
        return true;
    while (exp != n - 1) {
        if (tmp == n - 1)
            return true;
        exp <<= 1;
        tmp = fastmul(tmp, tmp, n);
    }
    return false;
}

bool miller_rabin(ll n, ll t = 15) {
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;

    static std::mt19937_64 randgen(std::chrono::system_clock::now().time_since_epoch().count());
    while (t--) {
		ll a = randgen() % (n-2) + 2; // 2 
		if (single_test(a, n) == false)
			return false;
	}
	return true;
}

void solve() {
	ll n, m;	cin >> n >> m;
	vector<ll> palin = genPalin(int(1e4));

	sort(palin.begin(), palin.end());
	// for (auto v : palin) {
	// 	cout << v << nln;
	// 	getch();
	// }
	
	vector<ll> palin_prime;
	for (auto v : palin)
		if (miller_rabin(v) == true) {
			palin_prime.push_back(v);
		}

	bool ans = false;
	for (auto v : palin_prime) {
		if (n <= v && v <= m) {
			cout << v << nln;
			ans = true;
		}
	}

	if (!ans)
		cout << 0 << nln;

}

int main(int argc, char* argv[]) {
	#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);

    int T = 1;
    //cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}