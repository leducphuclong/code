#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

const ll LIM = int(1e6)+5;
int main() {
	// INPUT

	// cin.tie(0)->sync_with_stdio(0);
	ll n, a, b;
	cin >> n >> a >> b;

	//Initialize
	ll min_dvs[LIM+1];
	fill(min_dvs, min_dvs + LIM + 1, 1);

	// ll cnt_dvs[LIM+1];
	// fill(cnt_dvs, cnt_dvs + LIM + 1, 2);

	// Eratosthenes Sieve to finding min divisor
	// for (ll i = 2; i*i <= LIM; ++i) {
	// 	for (ll j = i*i; j <= LIM; j += i)
	// 		if (min_dvs[j] == 1)
	// 			min_dvs[j] = i;
	// }

	// Eratosthense Sieve with to counting no divisors
	// cnt_dvs[0] = 0, cnt_dvs[1] = 1;
	// for (ll i = 2; i*i <= LIM; ++i) {
	// 	for (ll j = i*i; j <= LIM; j += i)
	// 		cnt_dvs[j] += 2;
	// 	cnt_dvs[i*i] -= 1;
	// }

	auto f = [&](ll n) -> ll {
	    ll res = 1;
	    while (n > 1) {
	    	ll d = min_dvs[n];
	       	res *=  d;
	       	while (min_dvs[n] == d)
	       		n /= d;
	    }
	    return res;
	};

	
	return 0;
}