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
    ll n;    cin >> n;
    string s;   cin >> s;
    ll al = 0, be = 0, SN = 0, EW = 0, cW = 0, cE = 0,
    cS = 0, cN = 0;
    for (auto c : s) {
        if (c == 'S')
            cS++;
        if (c == 'W')
            cW++;
        if (c == 'N')
            cN++;
        if (c == 'E')
            cE++;

        if (c == 'S' || c == 'N')
            SN++;
        if (c == 'E' || c == 'W')
            EW++;

        if (c == 'N')
            be++;
        else if (c == 'S')
            be--;
        if (c == 'E')
            al++;
        else if (c == 'W')
            al--;
    }

    // Pre check

    if (al & 1 || be & 1 || n == 1) {
        cout << "NO" << nln;
        return;
    }

    if (n == 2 and s[0] != s[1]) {
        cout << "NO" << nln;
        return;
    }

    ll rE = cE/2, rW = cW/2, rN = cN/2, rS = cS/2;

    auto print = [&] (char c1, char c2, ll &cnt) {
        if (c1 == c2) {
            if (cnt > 0) {
                cout << "R";
            } else {
                cout << "H";
            }
            cnt--;
        }
    };
    auto print2 = [&] (char c1, char c2, ll &cnt) {
        if (c1 == c2) {
            if (cnt > 0) {
                cout << "H";
            } else {
                cout << "R";
            }
            cnt--;
        }
    };

    // cout << rE << " " << rW << " " << rN << " " << rS << nln;

    for (auto c : s) {
        print(c, 'N', rN);
        print(c, 'S', rS);
        print2(c, 'E', rE);
        print2(c, 'W', rW);
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