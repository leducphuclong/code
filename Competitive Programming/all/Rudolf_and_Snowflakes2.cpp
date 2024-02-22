#include<bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef int64_t lo;

set<lo> ans;

void precompute() {
    for (lo k = 2; k <= static_cast<lo>(1e6); ++k) {
        lo sum = 1+k, A = k*k;
        for (lo p = 3; p <= 60; ++p) {
            sum += A;
            ans.insert(sum);
            if (sum > static_cast<lo>(1e18) || A*k > static_cast<lo>(1e18))
                break;
            A *= k;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    precompute();
    lo _;
    cin >> _;
    while (_--) {
        lo n;
        cin >> n;
        lo k = floor(sqrt(n-1));
        if ((k > 1 && k*(k+1) == n-1) || ans.count(n))
            cout << "YES" << nln;
        else
            cout << "NO" << nln;
    }
    // cerr << "OK" << nln;
    return 0;
}
