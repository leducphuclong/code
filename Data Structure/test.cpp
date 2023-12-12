#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

ll a[100005], n, x, d[100005], res = 0, tmp;

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; ++i) d[i] = a[i] == a[i - 1] ? d[i - 1] + 1 : 1;
	
	tmp = n;
	for (int i = 1; i <= n; ++i) {
		while(a[i] + a[tmp] > x) --tmp;
		if (a[tmp] == a[i]) {
			res += d[tmp] * (d[tmp] - 1) / 2;
			break;
		}
		if (a[tmp] < a[i]) break;
		if (a[i] + a[tmp] == x) res += d[tmp];
	}
	
	cout << res;
}