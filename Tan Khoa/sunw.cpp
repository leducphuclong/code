#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define nln '\n'

signed main() {

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;
	sort(arr.begin(), arr.end());

	int left = 0, right = n-1, cnt = 0;
	while (left < right) {
		if (arr[left] + arr[right] <= m) {
			left++, right--;
		} else {
			right--;
		}
		cnt++;
	}
	if (left == right)
		cnt++;
	cout << cnt << endl;

	return 0;
}