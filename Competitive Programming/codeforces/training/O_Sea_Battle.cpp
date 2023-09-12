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

// Constant
const lo N = 12;

// Declare global variables.
char mtx[N][N];
lo id[N][N], a[N], h[N]; bool d[N];
pair<lo, lo> dir[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void dfs(lo x, lo y, lo cnt) {
    id[x][y] = cnt;
    h[cnt]++;
    for (lo i = 0; i < 4; ++i) {
        lo u = x+dir[i].first, v = y+dir[i].second;
        if (mtx[u][v] == '#' && !id[u][v])
            dfs(u, v, cnt);
    }
}

void solve() {
    // Get the matrix
    for (lo i = 1; i <= 10; i++) {
        string s;
        getline(cin, s);
        for (lo j = 1; j <= 10; j++)
            mtx[i][j] = s[j-1];
    }
    // Find the id and the size of each ship
    lo cnt = 0;
    for (lo i = 1; i <= 10; ++i)
        for (lo j = 1; j <= 10; ++j)
            if (mtx[i][j] == '#' && id[i][j] == 0)
                dfs(i, j, ++cnt);
    // Commands
    lo und = 10, hit = 0, snk = 0;
    lo q;   cin >> q;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "SHOW") {
            cout << und << ' ' << hit << ' ' << snk << nln;    
        } else {
            lo x, y;
            cin >> x >> y;
            if (mtx[x][y] == '#' && !d[id[x][y]]) {
                mtx[x][y] = '*';
                a[id[x][y]]++;
                if (a[id[x][y]] == 1)
                    und--, hit++;
                if (a[id[x][y]] == h[id[x][y]]) {
                    if (a[id[x][y]])
                        hit--;
                    else
                        und--;
                    snk++, d[id[x][y]] = true;
                }
                    
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}