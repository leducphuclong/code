// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define lo int64_t
#define nln '\n'

const lo MOD = 1e9;

//using std::cout, std::cin, std::stdin, std::stdout, std::vector;
using namespace std;

lo fast_pow(lo a, lo b){
    if (b == 0)
        return 1;
    lo tmp = fast_pow(a, b/2);
    if (b % 2)
        return tmp%MOD*tmp%MOD*a%MOD;
    return tmp%MOD*tmp%MOD;
}

void solve() {
    freopen("MUL.INP", "r", stdin);
    freopen("MUL.OUT", "w", stdout);
    lo n;
    cin >> n;
    vector<lo> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    lo res = 0;
    for (lo i = 0; i < n; ++i){
        res += fast_pow(a[i], b[i]);
        res %= MOD;
    }
    cout << res << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
  return 0;
}
