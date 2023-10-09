// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;
typedef double db;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

db Vsphere(db r) {
    cout << "r: " << 4.0*M_PI << nln;
    return 4.0*M_PI*pow(r, 3)/3;
}

db Vintersection(db r, db d) {
    return 2.0/3*M_PI*pow(r-d/2.0, 2)*(2*r+d/2.0);
}

db distance(db x1, db y1, db z1, db x2, db y2, db z2) {
    return pow(x1-x2, 2)+pow(y1-y2, 2)+pow(z1-z2, 2);
}

struct point {
    db x, y, z;
};

void solve() {
    lo n;   cin >> n;
    db r;   cin >> r;
    vector<point> prr(n);
    for (auto &p : prr)
        cin >> p.x >> p.y >> p.z;
    
    cout << "r: " << r << nln;
    db V = Vsphere(r);
    for (lo i = 0; i < n-1; ++i) {
        // db d = distance(prr[i].x, prr[i].y, prr[i].z, prr[i+1].x, prr[i+1].y, prr[i+1].z);
        // V -= Vintersection(r, d);
    }
    // db d = distance(prr[0].x, prr[0].y, prr[0].z, prr.back().x, prr.back().y, prr.back().z);
    // V -= Vintersection(r, d);
    cout << (db)V << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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