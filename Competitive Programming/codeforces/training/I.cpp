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
const lo MOD = 1e9+7;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;   cin >> n;
    vector<lo> arr(n+1);
    for (lo i = 1; i <= n; ++i)
        cin >> arr[i];
    
    /* Idea:
    - Sort all sticks increasing
    - We calculate sum of consecutive stick by prefix sum
    - Let l run from 2 -> n-1, so (l+1) is the number of edges of the
    polygons considering
    - we take sum of l consecutive sticks in prefix sum array
    , don't care segment at begin, cuz it always <= sum,
    , find the first stick that >= sum, we can take the sticks
    from right after this consecutive sicks and right before that 
    found stick.
     */

    sort(arr.begin(), arr.end());

    vector<lo> pfs(n+1, 0);
    for (lo i = 1; i <= n; ++i)
       pfs[i] = pfs[i-1] + arr[i];

    lo ans = 0;
    for (lo l = 2; l <= n-1; ++l) {
        for (lo fi = 1; fi <= n-l+1; ++fi) {
            lo sum = pfs[fi+l-1] - pfs[fi-1];
            lo idx = lower_bound(arr.begin()+fi+l, arr.end(), sum) - arr.begin();
            ans += idx - (fi + l - 1) - 1;
        }
    }
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}