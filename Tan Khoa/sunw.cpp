#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;

    int left = 0, right = n-1, ans = 0;

    while (left < right) {
        if (arr[left] + arr[right] > x) {
            right--;
            ans++;
        } else {
            left++, right--;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
