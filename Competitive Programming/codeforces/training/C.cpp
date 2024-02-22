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
const lo N = 1e6+2;

// Declare global variables.
// End of global variable declaration.

void precompute() {
    // find the minimum divisor of all the numbers
}

lo find_ans(vector<lo> arr, lo n, bool odd) {
    lo g = 0;
    for (lo i = 0; i < n; ++i)
        if (i % 2 == odd)
            g = __gcd(g, arr[i]);

    for (int i = 0; i < n; ++i)
        if (i % 2 != odd && arr[i] % g == 0)
            return 0;

    return g;
}


void solve() {
    /* Idea
    - There is only two ways:
        - All elements at even are divisible by d (G1), and not even are not (G2)
        - Opposite
    - We will call them two group, G1, G2
    - find GCD of G1, d is a divisor of GCD (nlog)
        - check if all other elements in G2 whether is not divisible by d; (n*n(log(ai)))
    */
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
            cin >> v;
    // cout << find_ans(arr, n, 0);
    cout << max(find_ans(arr, n, 0), find_ans(arr, n, 1)) << endl;

}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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
