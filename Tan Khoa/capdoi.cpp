//#inculde <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	long long n, x;	cin >> n >> x;
	vector<long long> arr(n);
	for (auto &v : arr)
		cin >> v;

	sort(arr.begin(), arr.end());

	map<long long, long long> cnt;
	for (auto v : arr)
		cnt[v]++;

	vector<long long> brr;
	for (auto v : arr)
		if (brr.empty() || v != brr.back())
			brr.push_back(v);

	long long res = 0, l = 0, r = brr.size()-1;
	while (l < r) {

		if (brr[l] + brr[r] == x) {
			res += (long long)cnt[brr[l]]*cnt[brr[r]];
			if (arr[l]*2 == x) {
				res += (long long)cnt[arr[l]]*(cnt[arr[l]]-1)/2;
			}	
			l++;
		} else if (brr[l] + brr[r] > x) {
			r--;
		} else {
			l++;
		}
	}

	if (x % 2 == 0)
		res += cnt[x/2]*(cnt[x/2] - 1)/2;

	cout << res << endl;
	cerr << "It's all good, man!!" << endl;


	return 0;
}