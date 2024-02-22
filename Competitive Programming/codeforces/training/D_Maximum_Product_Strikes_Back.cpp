// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    /* Idea
    1. Remove all zeros, that means find all segment between two zeros
    2. Browse all segments
        - If multiplication of segment is positive -> compare to max
        - Else, remove a negative, choose from end or begin -> compare to max
     */
    vector<pair<vector<lo>, pair<lo,lo>>> seg;
    vector<lo> tmp;
    lo left = 0;
    for (lo i = 0; i < n; ++i) {
        lo v = arr[i];
        if (v != 0) {
            tmp.push_back(v);
        } else {
            if (!tmp.empty())
                seg.push_back({tmp, {left, i-1}});
            left = i+1;
            tmp.clear();
        }
    }

    if (!tmp.empty())
        seg.push_back({tmp, {left, n-1}});

    lo ans = 0, front = 0, rear = n;
    for (auto e : seg) {
        vector<lo> s = e.first;
        lo mul = 0;
        bool neg = false;
        for (auto v : s) {
            if (v < 0)
                neg ^= 1;
            mul += abs(v) == 2;
        }

        if (!neg) {
            if (mul >= ans) {
                ans = mul;
                front = e.second.first, rear = n - 1ll - e.second.second;
            }
        } else {
            lo m = s.size();

            lo begin = 0, i = 0;
            for (i = 0; i < m; ++i) {
                begin += abs(s[i]) == 2;
                if (s[i] < 0)
                    break;
            }

            lo end = 0, j = m-1;
            for (j = m-1; j >= 0; --j) {
                end += abs(s[j]) == 2;
                if (s[j] < 0)
                    break;
            }

            if (mul - begin >= ans) {
                ans = mul - begin;
                front = e.second.first + i + 1, rear = n - 1 - e.second.second;
            }

            if (mul - end >= ans) {
                ans = mul - end;
                front = e.second.first, rear = n - 1 - e.second.second + (m - 1 - j) + 1;
            }
        }
    }

    cout << front << ' ' << rear << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}