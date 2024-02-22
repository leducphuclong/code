// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
// dinh A, B, C, D, E, F, G, H, J, K, L tuong ung dinh 1, 2, 3
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

void Minimum_Path_From(char S, char F,
    map<char, int> nmd, map<int, char> rnm,
    vector<vector<int>> mdt,
    vector<vector<int>> pth) {
    int fin = nmd[F], sta = nmd[S];
    vector<char> trip;
    while (fin != sta) {
        trip.push_back(rnm[pth[sta][fin]]);
        fin = pth[sta][fin];
    }
    while (!trip.empty()) {
        cout << trip.back() << " -> ";
        trip.pop_back();
    }
    cout << F;
}

void solve() {
    // Input
    int n, m;
    cin >> n >> m;
    map<char, int> nmd;
    map<int, char> rnm;
    for (char i = 'A', j = 1; i <= 'Z'; ++i, ++j)
        nmd[i] = j, rnm[j] = i;
    nmd['J']--, rnm[nmd['J']] = 'J';
    nmd['K']--, rnm[nmd['K']] = 'K';
    nmd['L']--, rnm[nmd['L']] = 'L';
    // Build Weight Matrix
    vector<vector<int>> mtx(n+1, vector<int>(n+1, INT_MAX));
    vector<vector<int>> mdt(n+1, vector<int>(n+1, INT_MAX));
    vector<vector<int>> pth(n+1, vector<int>(n+1, INT_MAX));
    while (m--) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        mtx[nmd[u]][nmd[v]] = w;
        mtx[nmd[v]][nmd[u]] = w;

        mdt[nmd[u]][nmd[v]] = w;
        mdt[nmd[v]][nmd[u]] = w;

        pth[nmd[u]][nmd[v]] = nmd[u];
        pth[nmd[v]][nmd[u]] = nmd[v];
    }
    // Print Weight Matrix
    cout << "a) Ma tran trong so: " << nln;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if (mtx[i][j] == INT_MAX)
                cout << "I ";
            else
                cout << mtx[i][j] << ' ';
        cout << nln;
    }
    // Floy - Warshall Algorithm
    for (int i = 1; i <= n; ++i)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                if (mdt[u][i] != INT_MAX && mdt[i][v] != INT_MAX
                    && (mdt[u][i]+mdt[i][v]) < mdt[u][v]) {
                    mdt[u][v] = mdt[u][i]+mdt[i][v];
                    pth[u][v] = pth[i][v];
                }
    cout << "b) duong di ngan nhat tu D -> H: ";
    Minimum_Path_From('D', 'H', nmd, rnm, mdt, pth);
    cout << nln;
    cout << "Chi phi di tu D->H: " << mdt[nmd['D']][nmd['H']] << nln;
    cout << "c) duong di ngan nhat tu D -> H va qua canh BG: " << nln;
    Minimum_Path_From('D', 'B', nmd, rnm, mdt, pth);
    cout << " -> ";
    Minimum_Path_From('G', 'H', nmd, rnm, mdt, pth);
    cout << nln << "Chi phi: ";
    cout << mdt[nmd['D']][nmd['B']] + mdt[nmd['B']][nmd['G']] + mdt[nmd['G']][nmd['H']];
    cout << nln;
}   

int main(int argc, char* argv[]) {
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    return 0;
}
// Đây là Input của Slide bài giảng:
/*
11 21
A B 9
B C 5
A D 9
A E 6
E B 2
B F 5
B G 8
C G 7
C H 3
G H 4
F G 5
E F 7
D E 7
D J 4
E K 4
F K 4
G K 6
G L 4
H L 8
J K 1
K L 7
*/
