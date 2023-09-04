#include <bits/stdc++.h>

#define nln '\n'
typedef int64_t lo;

using namespace std;

const long double eps = 1e-5;

int pfs[int(1e6)+5];

int main() {
    // Input
    cin.tie(0)->sync_with_stdio(0);
    lo n, L, R;
    cin >> n >> L >> R;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    // Build Prefix Sum
    for (lo i = 1; i <= n; ++i)
        pfs[i] = pfs[i-1] + arr[i-1];
    // Solve
    for (lo i = )

    return 0;
}