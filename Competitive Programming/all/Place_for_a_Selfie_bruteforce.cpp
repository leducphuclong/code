// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>

typedef int64_t lo;
typedef lo line;

#define nln '\n'

using std::cout, std::cin, std::vector;

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
    vector<line> lne(n);
    for (auto &i : lne)
        cin >> i;
    vector<parabol> prb;
    for (lo i = 0; i < m; ++i){
        lo a, b, c;
        cin >> a >> b >> c;
        prb.push_back({a, b, c});
    }
    for (auto p : prb){
        bool ok = 0;
        for (auto l : lne)
            if (negative(p.a, p.b, p.c, l)){
                cout << "Yes" << nln;
                // cout << "Yes" << nln << l << nln;
                ok = 1;
                break;
            }
        if (!ok)
            cout << "No" << nln;
    }
    cout << nln;
}

int main(int argc, char* argv[]) {
    freopen("Place_for_a_Selfie.inp", "r", stdin);
    freopen("Place_for_a_Selfie.ans", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
  return 0;
}
