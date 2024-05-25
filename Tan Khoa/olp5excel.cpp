#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

ll str2num(string s) {
	ll n = 0;
	reverse(s.begin(), s.end());
	for (ll i = 0; i < s.size(); ++i) {
		cout << s[i]-'0' << nln;
		n += (s[i]-'0')*pow(10, i);
	}
	return n;
}

string num2str(ll n) {
	string s = "";
	while (n > 0) {
		s += n%10 + '0';
		n /= 10;
	}
	return s;
}

int main() {
	if (fopen("in", "r"))
		freopen("in", "r", stdin);

	cin.tie(0)->sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	cout << n << ' ' << m << nln;
	
	
	return 0;
}
