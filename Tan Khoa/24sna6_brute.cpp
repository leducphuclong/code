#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;	cin >> n >> k;
	ll arr[n];
	priority_queue<int> pq;
	for (auto& v : arr) {
		cin >> v;
		pq.push(v);
	}

	ll ans = 0;
	while (k--) {
		ans += pq.top();
		cout << pq.top() << nln;
		ll tmp = pq.top()-1;
		pq.pop();
		pq.push(tmp);
	}

	cout << ans << nln;

	return 0;
}