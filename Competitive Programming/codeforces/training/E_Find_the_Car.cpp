// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>
// #include <conio.h>

// Namespace
using namespace std;

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
    
}


void solve() {
    ll n, k , q;   cin >> n >> k >> q;
    vector<ll> point(k);
    for (auto &v : point)
        cin >> v;
    vector<ll> t(k);
    for (auto &v : t)
        cin >> v;
    
    vector<ll> segment(k);
    segment[0] = point[0];
    for (int i = 1; i < k; i++)
        segment[i] = point[i] - point[i-1];

    vector<ll> Time(k);
    Time[0] = t[0];
    for (int i = 1; i < k; ++i)
        Time[i] = t[i] - t[i-1];

    vector<ll> prefixSegment(k);
    prefixSegment[0] = segment[0];
    for (int i = 1; i < k; ++i)
        prefixSegment[i] = prefixSegment[i-1] + segment[i];

    vector<ll> prefixTime(k);
    prefixTime[0] = Time[0];
    for (int i = 1; i < k; ++i)
        prefixTime[i] = prefixTime[i-1] + Time[i];
    
    auto bs = [&](ll d) {
        ll l = 0, r = k-1, ans = -1;
        while (l <= r) {
            ll g = (l+r)/2;
            if (prefixSegment[g] <= d) {
                ans = g;
                l = g + 1;
            } else {
                r = g - 1;
            }
        }
        return ans;
    };

    auto solution = [&](ll d) {
        /// index of the longest distance <= d
        ll idx = bs(d);
        
        ll time = 0, distanceLeft = 0;
        if (idx != -1)
            time += prefixTime[idx],
            distanceLeft +=  d - prefixSegment[idx];

        ll overTime = 0;
        if (idx == -1 || distanceLeft > 0) {
            if (idx == -1) distanceLeft = d;
            overTime = distanceLeft * Time[idx+1] / segment[idx+1];
        }
        return time + overTime;
    };
    
    while (q--) {
        ll d;   cin >> d;
        cout << solution(d) << ' ';
    }
    cout << nln;

}

int main(int argc, char* argv[]) {
    #ifndef ONLINE_JUDGE
    //freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
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