#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> arr(n);
	for (auto &v : arr)
		cin >> v;

	sort(arr.begin(), arr.end());

	int left = 0, right = n-1;
	long long ans = 0;
	while (left < right) {
		if (arr[left] + arr[right] <= m) {
			ans += (long long)right-left;
			left++;
		} else {
			right--;
		}
	}

	cout << ans << endl;

	return 0;
}