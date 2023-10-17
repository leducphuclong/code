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
    lo n;  cin >> n;
    vector<lo> arr(n);
    for (lo i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    lo low = 0, hight = 1e9;
    while (low <= hight) {
        lo mid = (low+hight) >> 1;
        lo i = 0;
        while (i + 1 < n && arr[i+1] - arr[0] <= 2*mid)
            i++;
        lo j = n-1; 
        while (j - 1 >= 0 && arr.back() - arr[j-1] <= 2*mid)
            j--;
        ++i; --j;
        if (i > j || arr[j] - arr[i] <= 2*mid)
            hight = mid-1;
        else
            low = mid+1;
    }
    
    cout << hight+1 << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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