// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/* Theory of this lesson
    A technique is called stable sorting algorithm, meaning that
    elements with the same key value maintain their relative order
    in the sorted output.
*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

void counting_sort(vector<int> &arr, int n, int exp) {
    int cnt[10] = {0};
    for (auto v : arr)
        ++cnt[v/exp%10];

    for (int i = 1; i < 10; cnt[i] += cnt[i-1], ++i)
        continue;

    vector<int> out(n, 0);
    for (int i = n-1; i >= 0; --i) {
        cnt[arr[i]/exp%10]--;
        out[cnt[arr[i]/exp%10]] = arr[i];
    }
    arr = out;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; cin >> arr[i], ++i)
        continue;

    int max_e = *max_element(arr.begin(), arr.end());
    for (int exp = 1; exp <= max_e; exp *= 10)
        counting_sort(arr, n, exp);

    // Output
    for (auto i : arr)
        cout << i << ' ';
    cout << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    return 0;
}
