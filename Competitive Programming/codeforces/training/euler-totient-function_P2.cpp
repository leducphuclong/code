#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

#define int long long
#define nln '\n'

// Global Variables
vector<int> fb = {0, 1, 1};
map<int, int> cnt;
int n, power[88][60];
map<pair<int, int>, int> sav;
set<pair<int, int>> had;
// End Declaration

/*  Algorithm:
-> Find all posible quatity of each fibo numbers.
-> Try all ways with each fibo numbers until n > 18 or idx > 85
*/

int log(int a, int b) {
    if (b <= 1)
        return 0;
    return log2(a)/log2(b);
}

int fast_pow(int n, int m) {
    if (m == 0)
        return 1;
    int tmp = fast_pow(n, m/2);
    if (m % 2)
        return tmp*tmp*n;
    else
        return tmp*tmp;
}

int cal(int idx, int p, int n) {
    // cout << "idx: " << idx << nln;
    // cout << "p: " << p << nln;
    if (p > n)
        return 0;
    if (p == n) {
        // cout << "p: " << n << nln;
        // cout << "hiiiiii" << endl;
        // getch();
        return 1;
    }
    auto it = find(had.begin(), had.end(), make_pair(idx, p));
    if (it != had.end()) {
        return sav[*it];
    }
    if (idx == fb.size())
        return 0;
    int way = 0;
    for (int t = 0; t <= cnt[fb[idx]]; ++t) {
        if (p*power[idx][t] <= n)
            way += cal(idx+1, p*power[idx][t], n);
    }
    had.insert(make_pair(idx, p));
    return sav[make_pair(idx, p)] = way;
}

signed main() {
    // freopen("in", "r", stdin);
    // at most 87 fibo numbers with n = 1e18
    for (int i = 0; i < 85; ++i) {
        int len = fb.size();
        fb.push_back(fb[len-1] + fb[len-2]);
    }
    for (int i = 0; i < 88; ++i) {
        power[i][0] = 1;
        for (int p = 1; p < 60; ++p) {
            power[i][p] = fb[i] * power[i][p-1];
        }
    }
    // Solve
    int tc;     cin >> tc;
    while (tc--) {
        int n;  cin >> n;
        for (auto v : fb)
            cnt[v] = log(n, v);
        cout << cal(3, 1, n) << nln;
        // cout << "OK" << nln;
    }

    return 0;
}