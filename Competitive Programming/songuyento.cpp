// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

const lo N = 1e7+1;

// Declare global variables.
vector<bool> prime(N, 1);
vector<lo> pfs(N, 1);
lo a, b, k;

void precompute() {
    // sieve
    prime[0] = 0, prime[1] = 0;
    for (lo i = 2; i <= round(sqrt(N)); ++i)
        for (lo j = 2*i; j < N; j += i)
            prime[j] = 0;
    for (lo i = 1; i < N; ++i)
        pfs[i] = pfs[i-1]+prime[i];
}

bool check(lo l) {
    for (int x = a; x <= b-l+1; ++x)
        if (pfs[x+l-1]-pfs[x-1] < k)
            return 0;
    return 1;
}

void solve() {
    cin >> a >> b >> k;
    lo lef = 1, rig = b-a+1, res = -1;
    while (lef <= rig) {
        lo mid = (lef+rig)/2;
        if (check(mid))
            res = mid, rig = mid-1;
        else
            lef = mid+1;
    }
    cout << res << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
  return 0;
}
