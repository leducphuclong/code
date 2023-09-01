// Copyright (c) 2023, Le Duc Phuc Long

#include<stdio.h>  // NOLINT

using namespace std;  // NOLINT

#define nln '\n'

typedef int64_t lo;

const lo N = 100;

void show(lo n, double a[][N]) {
    for (lo i = 1; i <= n; ++i) {
        for (lo j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << nln;
    }
}

double determinant(lo n, double a[][N]) {
    if (n == 2)
        return a[1][1]*a[2][2]-a[1][2]*a[2][1];
    double res = 0;
    for (lo i = 1; i <= n; ++i) {
        double at[N][N];
        bool add = 0;
        for (lo x = 1; x <= n-1; ++x){
            for (lo y = 1; y <= n-1; ++y){
                if (y == i)
                    add = 1;
                at[x][y] = a[x+1][y+add];
            }
            add = 0;
        }
        res += a[1][i]*determinant(n-1, at)*((i % 2 == 1) ? 1 : -1);
    }
    return res;
}

void swapcol(double ai[][N], lo y, lo n, double a[][N]){
    for (lo j = 1; j <= n; ++j){
        lo c = j;
        if (j == y)
            c = n+1;
        for (lo i = 1; i <= n; ++i)
            ai[i][j] = a[i][c];
    }
}

bool krame(double res[N], lo n, double a[][N]){
    double dt = determinant(n, a);
    if (dt == 0)
        return 0;
    for (lo i = 1; i <= n; ++i){
        double ai[N][N];
        swapcol(ai, i, n, a);
        double di = determinant(n, ai);
        res[i] = di/dt;
    }
    return 1;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    lo n;
    cin >> n;
    double a[N][N];
    for (lo i = 1; i <= n; ++i)
        for (lo j = 1; j <= n+1; ++j)
            cin >> a[i][j];

    cout << "He phuong trinh ";
    double X[N];
    if (krame(X, n, a) == 0){
        cout << "vo nghiem!" << nln;
    } else {
        cout << "co nghiem la: " << nln;
        for (lo i = 1; i <= n; ++i)
            cout << "X" << i << ": " << X[i] << nln;
    }
    return 0;
}
