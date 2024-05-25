#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

ll max_beau = 0, n;
vector<ll> arr;

void bruteforce(ll cur_beau, ll city, ll ticket, ll prev_place) {
	if (city > n) {
		max_beau = max(max_beau, cur_beau);
		return;
	}


}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;	cin >> n;
	arr.resize(n+1);
	for (ll i = 1; i <= n; ++i)
		cin >> arr[i];



	return 0;
}