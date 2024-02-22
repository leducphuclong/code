// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'
#define Vmax 100

const int INF = INT_MAX;

// Declare global variables.

void get_data(int a[Vmax][Vmax], int V) {
    for (lo i = 1; i <= V; ++i)
        for (lo j = 1; j <= V; ++j) {
            cin >> a[i][j];
            if (a[i][j] == -1)
                a[i][j] = INF;
        }
}

void compact(int a[Vmax][Vmax], int V, int &S) {
    // cout << "S:" << S << nln;
    map<int, int> row, col;
    for (int i = 1; i <= V; ++i)
        row[i] = INT_MAX, col[i] = INT_MAX;

    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            if (a[i][j] < row[i])
                row[i] = a[i][j];
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j)
            if (a[i][j] != INF)
                a[i][j] -= (row[i]);
        if (row[i] > 0 && row[i] < INT_MAX) {
            S += row[i];
            // cout << "rowi: " << row[i]-INT_MAX << nln;
            // cout << "Sin: " << S << nln;
        }
    }


    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            if (a[i][j] < col[j])
                col[j] = a[i][j];
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j)
            if (a[i][j] != INF)
                a[i][j] -= (col[j]);
        if (col[i] > 0 && col[i] < INT_MAX)
            S += col[i];
    }
}

void show(int a[Vmax][Vmax], int V) {
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j)
            if (a[i][j] == INF)
                cout << "I ";
            else
                cout << a[i][j] << ' ';
        cout << nln;
    }
}

void find_edge(int a[Vmax][Vmax], int V, int &r, int &s) {
    int miv = INT_MIN;
    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            if (a[i][j] == 0) {
                int mivr = INT_MAX;
                for (int k = 1; k <= V; ++k)
                    if (a[i][k] != -1 && k !=j && a[i][k] < mivr)
                        mivr = a[i][k];

                int mivs = INT_MAX;
                for (int k = 1; k <= V; ++k)
                    if (a[k][j] != -1 && k != i && a[k][j] < mivs)
                        mivs = a[k][j];

                if (miv < (mivr + mivs)) {
                    miv = mivr + mivs;
                    r = i, s = j;
                }
            }
}

void branching1(int a[Vmax][Vmax], int V, int r, int s, int start) {
    for (int k = 1; k <= V; ++k)
        a[r][k] = INF, a[k][s] = INF;
    a[s][r] = INF;
    a[s][start] = INF;
}

int main(int argc, char* argv[]) {
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int V;
    cin >> V;
    int a[Vmax][Vmax];
    get_data(a, V);
    int S = 0;
    compact(a, V, S);
    int r, s;
    find_edge(a, V, r, s);
    int start = r;
    branching1(a, V, r, s, start);
    cout << r << " ~ " << s << nln;
    for (int tms = 1; tms <= V-2; ++tms) {
        compact(a, V, S);
        find_edge(a, V, r, s);
        branching1(a, V, r, s, start);
        show(a, V);
        getch();    
        cout << nln << nln << nln;
    }
    compact(a, V, S);
    cout << "sum: " << S << nln;
    show(a, V);

    return 0;
}
