#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	vector<pair<int, int>> els;
	for (int i = 0; i < n; ++i)
		els.push_back(make_pair(arr[i], i+1));
	sort(els.begin(), els.end());

	vector<int> idx = {-1, -1, -1};
	for (int f = 0; f < n-2; ++f) {
		int tmp = s - els[f].first;
		int s = f+1, t = n-1;
		while (s < t) {
			if (els[s].first + els[t].first < tmp) {
				s++;
			} else if (els[s].first + els[t].first > tmp) {
				t--;
			} else {
				idx = {els[f].second, els[s].second, els[t].second};
				break;
			}
		}
	}

	if (idx[0] != 1) {
		sort(idx.begin(), idx.end());
		for (auto v : idx)
			cout << v << ' ';
		cout << nln;
	} else {
		cout << "IMPOSSIBLE" << nln;
	}


    return 0;
}