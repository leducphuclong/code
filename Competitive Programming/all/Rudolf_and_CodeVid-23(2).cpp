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
struct medicine {
    lo day, good, bad;
};

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    cout << "hi" << nln;
    return;
    lo n, m, w = LLONG_MIN;
    cin >> n >> m;
    vector<medicine> med(m);
    bitset<10> status;
    cin >> status;
    for (auto &v : med) {
        cin >> v.day;
        w = max(w, v.day);
        bitset<10> tmp;
        cin >> tmp;
        v.good = static_cast<lo>(tmp.to_ullong());
        cin >> tmp;
        v.bad = static_cast<lo>(tmp.to_ullong());
    }

    // for (auto v : med)
    //     cout << v.good << " ~ " << v.bad << " : " << v.day << nln;

    lo s = static_cast<lo>(status.to_ullong());
    vector<lo> bucket[w*1024];
    bucket[0].push_back(0);
    queue<lo> process ({0});
    while (!process.empty()) {
        cout << process.front();
        process.pop();
    }
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