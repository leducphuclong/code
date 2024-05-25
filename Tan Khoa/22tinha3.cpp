// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

ll sumSequence(ll first, ll last, ll step) {
	return (first+last)*(((last - first)/step)+1)/2;
}

ll f(ll x) {
	return sumSequence(2, x - x%2, 2) - sumSequence(6, x - x%6, 6);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll a, b;	cin >> a >> b;
	cout << (f(b-1) - f(a)) << nln;

	return 0;
}