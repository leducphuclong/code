#include<conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

lo n, cnt = 1;
vector<lo> arr(1, 0), res;

void precompute() {
}

void rc(lo i) {
    if (i > n) {
        if (res.empty())
            return;
        for (auto x : res)
            cout << x << ' ';
        cout << nln;
        ++cnt;
        return;
    }
    res.push_back(arr[i]);
    rc(i+1);
    res.pop_back();
    rc(i+1);
}

void solve() {
    cin >> n;
    for (lo i = 1; i<= n; ++i)
        arr.push_back(i);
    cout << "Cac tap con thuoc X la: " << nln;
    rc(1);
    cout << "So luong(tinh ca tap rong): " << cnt << nln;
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
  return 0;
}
