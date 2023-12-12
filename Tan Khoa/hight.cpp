#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> boy(n);
	for (auto &v : boy)
		cin >> v;

	vector<int> girl(m);
	for (auto &v : girl)
		cin >> v;

	sort(boy.begin(), boy.end());
	sort(girl.begin(), girl.end());

	int i1 = 0, i2 = 0, ans = 0;
	while (i1 < n && i2 < m) {
		if (abs(boy[i1] - girl[i2]) <= k) {
			ans++;
			i1++, i2++;
		} else { // abs(boy[i1] - girl[i2] > k)
			if (boy[i1] - girl[i2] > k) {
				++i2;
			} else { // boy[i2] - girl[i1] > k
				++i1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}