// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::set;
using std::map;
using std::string;
using std::lower_bound;
using std::upper_bound;

typedef int64_t lo;

#define nln '\n'

struct parabol {
    lo a, b, c;
};

lo sqr(lo x) {
    return x*x;
}

bool negative(lo a, lo b, lo c, lo k) {
    return ((sqr(b-k) - 4*a*c) < 0);
}

void solve() {
    // Input
    lo n, m;
    cin >> n >> m;
    vector<lo> lne(n);
    for (auto &i : lne)
        cin >> i;
    vector<parabol> prb(m);
    for (auto &i : prb)
        cin >> i.a >> i.b >> i.c;
    // Sort
    sort(lne.begin(), lne.end());
    // Find
    for (auto p : prb) {
        // cout << "pb: " << p.b << nln;
        lo cs1 = -1 , cs2 = -1;
        bool ck1 = 1, ck2 = 1;
        // Greatest number smaller than or equal to
        auto it = upper_bound(lne.begin(), lne.end(), p.b);
        if (it != lne.begin()) {
            --it;
            cs1 = *it;
        } else {
            ck1 = 0;
        }
        // Smallest number greater than or equal to
        it = lower_bound(lne.begin(), lne.end(), p.b);
        if (it != lne.end()) {
            cs2 = *it;
        } else {
            ck2 = 0;
        }
        if (ck1 && negative(p.a, p.b, p.c, cs1)) {
            // cout << "Yes" << nln;
            cout << "Yes" << nln << cs1 << nln;
            continue;
        }

        if (ck2 && negative(p.a, p.b, p.c, cs2)) {
            // cout << "Yes" << nln;
            cout << "Yes" << nln << cs2 << nln;
            continue;
        }

        cout << "No" << nln;
    }
    cout << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
  return 0;
}
