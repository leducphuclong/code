#include <bits/stdc++.h>

using namespace std;

#define long long int
#define nln '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;   cin >> n >> m;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;

    sort(arr.begin(), arr.end());

    int left = 0, right = n-1, ans = 0;

    while (left < right) {
        if (arr[left] + arr[right] > m) {
            right -= 1;
        } else if (arr[left] + arr[right] < m) {
            left -= 1;
        } else {
            ans += right - left;
            right -= 1;
        }
    }

    cout << ans << nln;

    return 0;
}
