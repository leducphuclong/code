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

// Declare global variables.
vector<string> cafe =  {"###.?????", 
                        "###.?????", 
                        "###.?????", 
                        "....?????", 
                        "?????????", 
                        "?????....", 
                        "?????.###",
                        "?????.###",
                        "?????.###",};

char mtx[102][102];    lo n, m;    

// End of global variable declaration.

bool check(lo x, lo y) {
    x--, y--;
    // Check if there is enough space
    if (x+9-1 >= n || y+9-1 >= m)
        return false;
    // Check the cells in top-left are black
    for (lo i = 0; i < 3; ++i)
        for (lo j = 0; j < 3; ++j)
            if (mtx[x+i][y+j] == '.' || mtx[x+9-1-i][y+9-1-j] == '.')
                return false;
    // Check the adjacent cells
    
    for (lo k = 0; k < 4; ++k)
        if (mtx[x+k][y+3] == '#' || mtx[x+3][y+k] == '#' 
            || mtx[x+9-1-3][y+9-1-3+k] == '#' ||mtx[x+9-1-3+k][y+9-1-3] == '#')
            return false;
    return true;
}

void precompute() {
}

void solve() {
    // Input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;    cin >> str;
        for (int j = 0; j < m; ++j)
            mtx[i][j] = str[j];
    }
    // Find
    vector<pair<lo, lo>> ans;
    for (lo i = 0; i < n; ++i)
        for (lo j = 0; j < m; ++j)
            if (check(i, j))
                ans.push_back({i, j});
    sort(ans.begin(), ans.end());
    for (auto v : ans)
        cout << v.first << ' ' << v.second << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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