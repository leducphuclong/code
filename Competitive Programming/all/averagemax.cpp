// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n, a, b;
    cin >> n >> a >> b;
    vector<lo> arr = {0};
    for (lo i = 0; i < n; ++i) {
        lo x;
        cin >> x; arr.push_back(x);
    }
    // Build Prefix Sum
    vector<lo> pfs = {0};
    for (lo i = 1; i <= n; ++i)
        pfs.push_back(pfs.back()+arr[i]);
    // Solve
    lo l = 1, r = a;
    double max_avr = (double)pfs[a] / a;
    cout << a << nln;
    cout << pfs[a] << nln;
    cout << max_avr << nln;

    while (r <= n) {
        double current_avr = (double)(pfs[r]-pfs[l-1]) / (r-l+1);
        if (r-l+1 < b) {
            ++r;
            current_avr = (double)(pfs[r]-pfs[l-1]) / (r-l+1);
            if (current_avr > max_avr)
                max_avr = current_avr;
        } else { // r-l+1 only can be less than or equal to b
            do {
                ++l;
                current_avr = (double)(pfs[r]-pfs[l-1]) / (r-l+1);
                if (current_avr > max_avr)
                    max_avr = current_avr;
            } while (r-l+1 >= a);e
        }
        cout << l << " ~ " << r << nln;
        cout << "current_avr: " << current_avr << nln;
        cout << "max avr: " << max_avr << nln;
    }
    cout << setprecision(4) << fixed << max_avr << nln;
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
