#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define int long long

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	set<int> curr;
	int left = 0, right = 0;
	while (right < k)
		curr.insert(arr[right++]);

	while (right < )


	return 0;
}