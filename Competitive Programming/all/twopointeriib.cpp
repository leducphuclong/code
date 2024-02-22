#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nln '\n'

const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, s;   cin >> n >> s;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;

    int left = 0, right = 0, min_length = -1, curr = 0;
    while (right < n) {
        if (curr + arr[right] < s) {
            curr += arr[right++];
        } else {
            if (min_length == -1 || right - left + 1 < min_length) {
                min_length = right - left + 1;
            }
            curr -= arr[left++];
            if (left > right)
                right++;
        }
    }

    cout << min_length << nln;

    return 0;
}