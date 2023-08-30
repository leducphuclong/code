#include <bits/stdc++.h>  

using namespace std;  

int n, k, cnt = 0;
vector<int> res;
vector<bool> vst(n+1, 0);

void rc(int i ) {
    if (i > k) {
        ++cnt;
        for (auto x : res)
            cout << x << ' ';
        cout << endl;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (!vst[j]) {
            res.push_back(j);
            vst[j] = 1;
            rc(i+1);
            vst[j] = 0;
            res.pop_back();
        }
    }
}

int main() {
    cin >> n >> k;
    rc(1);
    cout << cnt << endl;
    return 0;
}
