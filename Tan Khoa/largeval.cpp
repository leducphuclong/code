#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	int res = (arr[arr.size()-2]-arr[0])*(arr[arr.size()-1]-arr[1]);
	cout << res << endl;

    return 0;
}
