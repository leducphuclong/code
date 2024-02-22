#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

void generate(string p, vector<string>& res, int left, int right, int n) {
	if (left == n && right == n) {
		res.push_back(p);
		return;
	}
	if (left < n)
		generate(p+'(', res, left + 1, right, n);
	if (right < left)
		generate(p+')', res, left, right + 1, n);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin >>n;

	vector<string> res;
	generate("", res, 0, 0, n);
	for (auto v : res)
		cout << v << nln;

    return 0;
}