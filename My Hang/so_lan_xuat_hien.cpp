#include <bits/stdc++.h>
#include <map> // -> TLE
#include <unordered_map>

using namespace std;

int main() {
	map<long long, long long> cnt;
	long long x;
	while (cin >> x) {
		cnt[x]++;
	}

	for (auto p : cnt)
		cout << p.second << endl;
	return 0;
}