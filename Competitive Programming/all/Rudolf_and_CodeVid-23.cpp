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
    lo n, m;
    cin >> n >> m;
    vector<medicine> med(m);
    bitset<10> status;
    cin >> status;
    for (auto &v : med) {
        cin >> v.day;
        bitset<10> tmp;
        cin >> tmp;
        v.good = static_cast<lo>(tmp.to_ullong());
        cin >> tmp;
        v.bad = static_cast<lo>(tmp.to_ullong());
    }

    // for (auto v : med)
    //     cout << v.good << " ~ " << v.bad << " : " << v.day << nln;

    lo s = static_cast<lo>(status.to_ullong());

    vector<lo> cost(1024, LLONG_MAX);
    cost[s] = 0;
    priority_queue<pair<lo, lo>, vector<pair<lo, lo>>, greater<pair<lo, lo>>> optimized;
    optimized.push({0, s});

    while (!optimized.empty()) {
        for (auto v : med) {
            lo nbh = optimized.top().second & ~(v.good) | v.bad;
            if (cost[nbh] > optimized.top().first+v.day) {
                cost[nbh] = optimized.top().first+v.day;
                optimized.push({cost[nbh], nbh});
            }
        }
        optimized.pop();
    }
    cout << (cost[0] == LLONG_MAX ? -1 : cost[0]) << nln;
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