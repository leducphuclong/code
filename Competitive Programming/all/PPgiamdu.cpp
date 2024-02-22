// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

const lo N = 100;

// Declare global variables.
double a[N][N], v[N];
lo n;

void precompute() {
    cin >> n;
    for (lo i = 1; i <= n; ++i)
        for (lo j = 1; j <= n+1; ++j)
            cin >> a[i][j];
    for (lo i = 1; i <= n; ++i)
        cin >> v[i];
}

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void solve() {
    double r[N];  // mảng số dư
    // Bien doi he phuong trinh (1) ve dang (2)
    for (lo i = 1; i <= n; ++i) {
        lo t = a[i][i];
        for (lo j = 1; j <= n+1; ++j)
            a[i][j] = a[i][j] / t;
        a[i][i] = 1;
    }
    // Tính các số dư ban đầu
    for (lo i = 1; i <= n; ++i) {
        r[i] = a[i][n+1];
        for (lo j = 1; j <= n; ++j)
            r[i] -= a[i][j]*v[j];
    }
    // for (lo i = 1; i <= n; ++i)
    //     cout << r[i] << ' ';
    // cout << nln;
    while (1) {
        double rs = r[1], lct = 1;
        for (lo i = 2; i <= n; ++i)
            if (r[i] > rs) {
                rs = r[i];
                lct = i;
            }
        v[lct] = 
        break;
    }   
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
