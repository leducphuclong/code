#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<int> arr;
	int x;
	while (cin >> x)
		arr.push_back(x);
	int k = 3;
	vector<int> dp(arr.size()+1, 0);
	for (int i = 1; i <= k; ++i)
            dp[i] = *max_element(arr.begin(), arr.begin()+i) * i;
    
    for (auto v : dp)
		cout << v << ' ';
	cout << nln;

	for (int i = k+1; i <= static_cast<int>(arr.size()); ++i)
        for (int j = i-k+1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[j-1] + *max_element(arr.begin()+j-1, arr.begin()+i)*(i-j+1));
            if (i == 4) {
            	cout << j << ": " << dp[i] << nln;
            }
        }

	for (auto v : dp)
		cout << v << ' ';
	cout << nln;
	for (auto v : arr)
		cout << v << ' ';
	cout << nln;
	
	return 0;
}