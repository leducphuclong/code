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
int mtx[3][3];
// End of global variable declaration.

void precompute() {
    
}

void solve() {
    vector<lo> arr(9);
    for (auto &v : arr)
        cin >> v;

    vector<lo> pmt(9);
    iota(begin(pmt), end(pmt), 0);

    vector<tuple<int, int, int>> row{{0, 1, 2}, // 1-st row from the top
                                    {3, 4, 5}, // 2-nd row from the top
                                    {6, 7, 8}, // 3-rd row from the top
                                    {0, 3, 6}, // 1-st column from the left
                                    {1, 4, 7}, // 2-nd column from the left
                                    {2, 5, 8}, // 3-rd column from the left
                                    {0, 4, 8}, // top-left to bottom-right
                                    {2, 4, 6}};// top-right to bottom-left

    lo omg = 362880, cnt = 0;
    do {
        bool dsp = false;
        for (auto &&[a, b, c] : row)
            if (arr[a] == arr[b] && pmt[a] < pmt[c] && pmt[b] < pmt[c])
                dsp = true;
            else if (arr[a] == arr[c] && pmt[a] < pmt[b] && pmt[c] < pmt[b])
                dsp = true;
            else if (arr[c] == arr[b] && pmt[c] < pmt[a] && pmt[b] < pmt[a])
                dsp = true;
        if (!dsp)
            cnt++;
    } while (next_permutation(pmt.begin(), pmt.end()));
    cout << setprecision(8) << (double)cnt/omg << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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