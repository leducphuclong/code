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
struct  shock {
    string type, side;
    lo quantity;
};

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    // input and little precompute
    lo n;
    cin >> n;
    shock arr[n];
    lo total = 0;
    map<string, bool> pairs;
    map<string, lo> anys;
    map<string, lo> quantitys;
    map<string, lo> special_anys;
    for (lo i = 0; i < n; ++i) {
        getline(cin, arr[i].type, ' ');
        getline(cin, arr[i].side, ' ');
        cin >> arr[i].quantity;
        total += arr[i].quantity;
        if (arr[i].side == "any") {
            anys[arr[i].type] = arr[i].quantity;
            if (quantitys[arr[i].type])
                special_anys[arr[i].type] = 1;
            continue;
        }
        if (anys[arr[i].type])
            special_anys[arr[i].type] = 1;
        else
            anys.erase(arr[i].type);
        if (pairs[arr[i].type] == 1) {
            pairs[arr[i].type] = 0;
            if (quantitys[arr[i].type] < arr[i].quantity)
                quantitys[arr[i].type] = arr[i].quantity;
        } else {
            pairs[arr[i].type] = 1;
            quantitys[arr[i].type] = arr[i].quantity;
        }
    }
    // Solve
    lo res = 0;
    for (auto i : pairs)
        res += quantitys[i.first];
    res = res + anys.size() - special_anys.size();
    if (res < total)
        cout << res + 1;
    else
        cout << "impossible";
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
