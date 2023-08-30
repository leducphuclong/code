// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.
vector<vector<map<lo, bool>>> vst;
lo n, m, x1, y1, x2, y2;
string drt;

void precompute() {
}

bool corner() {
    return (x1 == 1 && y1 == 1) || (x1 == 1 && y1 == m) || (x1 == n && y1 == 1)
    || (x1 == n && y1 == m);
}

void hit_the_corner() {
    if (x1 == 1 && y1 == 1) {
        drt = "DR";
        return;
    }
    if (x1 == 1 && y1 == m) {
        drt = "DL";
        return;
    }
    if (x1 == n && y1 == 1) {
        drt = "UR";
        return;
    }
    if (x1 == n && y1 == m) {
        drt = "UL";
        return;
    }
}

bool maindiagonal() {
    if (drt == "DR" || drt == "UL")
        return 1;
    return 0;
}

void hit_the_wall() {
    if (drt == "DR") {
        if (x1 == n)
            drt = "UR";
        else
            drt = "DL";
        return;
    }
    if (drt == "DL") {
        if (x1 == n)
            drt = "UL";
        else
            drt = "DR";
        return;
    }
    if (drt == "UR") {
        if (x1 == 1)
            drt = "DR";
        else
            drt = "UL";
        return;
    }
    if (drt == "UL") {
        if (x1 == 1)
            drt = "DL";
        else
            drt = "UR";
        return;
    }
}

bool firstfly() {
    if (x1 == x2 && y1 == y2)
        return 1;
    do {
        if (drt == "DR") {
            if (x1 < n && y1 < m)
                x1++, y1++;
        }
        if (drt == "DL") {
            if (x1 < n && y1 > 1)
                x1++, y1--;
        }
        if (drt == "UR") {
            if (x1 > 1 && y1 < m)
                x1--, y1++;
        }
        if (drt == "UL") {
            if (x1 > 1 && y1 > 1)
                x1--, y1--;
        }
        if (x1 == x2 && y1 == y2)
            return 1;
    } while ((1 < x1 && x1 < n && 1 < y1 && y1 < m));
    return 0;
}

void fly() {
    if (drt == "DR") {
        if (n-x1 < m-y1)
            y1 += n-x1, x1 = n;
        else
            x1 += m-y1, y1 = m;
    }
    if (drt == "DL") {
        if (n-x1 < y1-1)
            y1 -= n-x1, x1 = n;
        else
            x1 += y1-1, y1 = 1;
    }
    if (drt == "UR") {
        if (x1-1 < m-y1)
            y1 += x1-1, x1 = 1;
        else
            x1 -= m-y1, y1 = m;
    }
    if (drt == "UL") {
        if (x1-1 < y1-1)
            y1 -= x1-1, x1 = 1;
        else
            x1 -= y1-1, y1 = 1;
    }
}

bool bounce(lo &cnt) {
    if (maindiagonal()) {
        lo d;
        if (drt == "DR")
            d = 1;
        else
            d = 0;
        if (vst[1][d][x1-y1] == 1) {
            return 0;
        }
        vst[1][d][x1-y1] = 1;
        if (x1-y1 == x2-y2)
            return 1;
    } else {
        int d;
        if (drt == "UR")
            d = 1;
        else
            d = 0;
        if (vst[0][d][x1+y1] == 1)
            return 0;
        vst[0][d][x1+y1] = 1;
        if (x1+y1 == x2+y2)
            return 1;
    }
    fly();
    if (corner())
        hit_the_corner();
    else
        hit_the_wall();
    ++cnt;
    return bounce(cnt);
}

void solve() {
    // Input
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    cin.ignore();
    getline(cin, drt, nln);
    // Process
    vst.resize(2, vector<map<lo, bool>> (2));
    lo cnt = 0;
    if (firstfly()) {
        cout << 0 << nln;
        return;
    }
    if (corner())
        hit_the_corner();
    else
        hit_the_wall();
    cnt++;
    if (bounce(cnt))
        cout << cnt << nln;
    else
        cout << -1 << nln;
    vst.clear();
}

int main(int argc, char* argv[]) {
    // freopen("bouncyball.inp", "r", stdin);
    // freopen("bouncyball.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
  return 0;
}
