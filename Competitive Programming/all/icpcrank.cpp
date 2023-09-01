#include <bits/stdc++.h>  // NOLINT

using namespace std;

#define nln '\n'

typedef int64_t lo;

bool compare(pair<lo, lo> left, pair<lo, lo> right) {
    if (left.first != right.first)
        return left.first > right.first;
    return left.second < right.second;
}


int main(int argc, char** argv) {
    // freopen(argv[1], "r", stdin);
    // freopen(argv[2], "w", stdout);
    lo n;
    cin >> n;
    pair<lo, lo> arr[n];
    for (lo i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n, compare);
    for (lo i = 0; i < n ; ++i)
        cout << arr[i].first << ' ' << arr[i].second << nln;
    return 0;
}
