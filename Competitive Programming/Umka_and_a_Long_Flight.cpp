// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <numeric>

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
using std::pair;

typedef int lo;

#define nln '\n'

const lo TLE = 1e8*3, N = 46;

lo fb[N];

void precompute() {
    fb[0] = 1, fb[1] = 1;
    for (lo i = 2; i <= N-1; ++i)
        fb[i] = fb[i-1]+fb[i-2];
}

bool solve(lo n, lo x, lo y) {
    // cout << "n: " << n << nln;
    // cout << "x: " << x << nln;
    // cout << "y: " << y << nln;
    // getch();
    if (n == 1)
        return 1;
    if (fb[n-1] < y && y <= fb[n])
        return 0;
    return solve(n-1, y%fb[n], x);
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        lo n, x, y;
        cin >> n >> x >> y;
        if (solve(n, x, y))
            cout << "YES";
        else
            cout << "NO";
        cout << nln;
    }
  return 0;
}
