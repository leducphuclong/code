#include <iostream>

using namespace std;

#define nln '\n'
typedef long long ll;

ll sum_dvs(ll n) {
	ll s = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0) {
			if (i*i == n)
				s += i;
			else
				s += (i + n/i);
		}
	return s-n;
}

int main() {
	ll n = 8501, cnt = 0;
	for (ll i = 0; i < n; ++i)
		if (sum_dvs(i) == i) {
			cout << i << nln;
			cnt++;
		}
	cout << cnt << nln;
	return 0;
}