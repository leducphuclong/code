// Le Duc Phuc Long, 2024

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

bool checkPalin(vector<ll> num) {
	ll left = 0, right = num.size()-1;
	while (left < right) {
		if (num[left++] != num[right--])
			return false;
	}
	return true;
}

bool canCopyLeft(vector<ll> num) {
	ll left = num.size()/2;
	while (left >= 0) {
		ll right = num.size()- 1 - left;
		if (num[left] != num[right])
			if (num[left] > num[right])
				return false;
			else
				return true;
		left -= 1;
	}
	return true;
}

void copyLeft(vector<ll>& num) {
	ll left = num.size()/2;
	while (left >= 0) {
		ll right = num.size() - 1 - left;
		num[right] = num[left];
		left -= 1;
	}
}

bool isSpecial(vector<ll> num) {
}

vector<ll> previousPalin(vector<ll> num) {
	// we run inside out
	// When we didn't decrease
	// if s[left] == s[right] -> we continue
	// if s[left]  > s[right] 
	// -> s[left] -= 1
	// -> s[right] = s[left]
	// deced = true
	// if s[left] < s[right]
	// s[right]  = s[left]
	// deced = true

	// When we deced
	// if s[left] > s[right]
		// s[right] = s[left]
	// if s[left] < s[right]
		// s[left] = s[right]

	if (checkPalin(num))
		return num;

	if (canCopyLeft(num)) {
		copyLeft(num);
		return num;
	}

	if (num[num.size()/2]) {
		num[num.size()/2]--;
		ll l = num.size()/2-1;
		while (l >= 0) {
			ll r = num.size() - 1 - l;
			num[r] = num[l];
			l--;
		}
		return num;
	}

	ll left = num.size()/2-1;
	bool deced = false;
	while (left >= 0) {
		ll right = num.size() - 1 - left;
		if (num[left] > num[right]) {
			if (!deced) {
				ll k = num.size()/2;
				while (num[k] == 0)
					k--;
				num[k]--;
				num[num.size() - 1 - k] = num[k];
				for (ll j = k+1; j <= num.size()-1-k-1; ++j)
					num[j] = 9;
				deced = true;
				num[right] = num[left];
			} else {
				num[right] = num[left];
			}
		} else {
			num[right] = num[left];
		}
		left--;
	}
	return num;
}

vector<ll> convertToVector(ll n) {
	vector<ll> num;
	while (n > 0) {
		num.push_back(n % 10);
		n /= 10;
	}
	reverse(num.begin(), num.end());
	return num;
}

vector<ll> findPalin(ll n) {
	vector<ll> num = convertToVector(n);
	while (checkPalin(num) == false) {
		num = convertToVector(--n);
	}
	return num;
}

void viewVector(vector<ll> v) {
	for (auto val : v) 
		cout << val << ' ';
	cout << nln;
}

ll NoOddPalinWithEvenN(ll sizeOfNum) {
	ll n = sizeOfNum/2, res = 0;
	for (ll i = 1; i <= n; ++i)
			res += pow(10, i-1)*9;
		return res;
}

ll NoOddPalin(ll n) {
	vector<ll> num = convertToVector(n);
	if (num.size() % 2 == 0) {
		return NoOddPalinWithEvenN(num.size());
	} else {
		ll res = num[0]*NoOddPalinWithEvenN(num.size());
		cout << "res: " << res << nln;
		num = previousPalin(num);
		viewVector(num);
		ll half = num.size()/2;
		// for (ll i = 0; i <= half; ++i) {
		// 	res += num[i]*pow(10, half-i);
		// }
		ll add = 0;
		for (ll j = 1; j <= half; ++j)
			add += num[j]*pow(10, half-j);
		res += add+num[0];
		cout << "add: " << add << nln;
		return res;
	}
}

ll NoOddPalinBrute(ll n) {
	ll cnt = 0;
	for (ll i = 1; i <= n; ++i) {
		vector<ll> num = convertToVector(i);
		if (num.size() % 2 == 1 && checkPalin(num) == true) {
			viewVector(num);
			cnt++;
		}
	}
	return cnt;
}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// ll n;   
	// cin >> n;
	// for (ll i = 1000; i <= int(1e7); ++i) {
	// 	vector<ll> num = convertToVector(i);
	// 	if (num.size() % 2 == 0)
	// 		continue;
	// 	if (findPalin(i) != previousPalin(num)) {
	// 		cout << "Wrong" << nln;
	// 		cout << i << nln;
	// 		viewVector(findPalin(i));
	// 		viewVector(previousPalin(num));
	// 		cin.get();
	// 	}
	// }
	freopen("in", "r", stdin);
	ll l, r;
	cin >> l >> r;
	cout << "r: " << r << nln;
	cout << NoOddPalinBrute(r)<< nln;

	return 0;
}