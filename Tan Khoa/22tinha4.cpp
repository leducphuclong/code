// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll a, b;	cin >> a >> b;
	vector<ll> arr;
	while (a > 0) {
		arr.push_back(a % 10);
		a /= 10;
	}
	reverse(arr.begin(), arr.end());
	vector<ll> brr;
	while (b > 0) {
		brr.push_back(b % 10);
		b /= 10;
	}
	reverse(brr.begin(), brr.end());

	vector<ll> crr;

	vector<bool> used(brr.size());
	ll j = 0, i = 0;

	while (j < brr.size()) {
		while (i < arr.size() && arr[i] <= brr[j]) {
			crr.push_back(arr[i]);
			i++;
		}
		crr.push_back(brr[j]);
		++j;
	}

	while (i < arr.size()) {
		crr.push_back(arr[i]);
		i++;
	}

	for (auto v : crr)
		cout << v;

	return 0;
}