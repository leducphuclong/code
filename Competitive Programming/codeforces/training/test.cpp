// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo m, n;        cin >> m >> n;
    int arr[m][n];
    for (lo i = 0; i < m; ++i)
        for (lo j = 0; j < n; ++j)
            cin >> arr[i][j];
    /* Idea
    1. We first sort every good of shops decreasing
        - Attached shop's idex and persin's index
        - Put them into a vector
    2. Browse the vector:
        - If the number of visited shop is full of n-1, and came
        to new shop, then conintue
            - Else:
            - If the person's index is not received gift, take the good and
            mark that idexed already done
                - Else, continue browse
    */

    vector<pair<lo, pair<lo, lo>>> in4;
    for (lo i = 0; i < m; ++i)
        for (lo j = 0; j < n; ++j)
            in4.push_back({arr[i][j], {i, j}});
    
    sort(in4.rbegin(), in4.rend());
    lo cnt_visited = 0;
    bool received[n], visited[m];
    memset(received, false, sizeof(received));
    memset(visited, false, sizeof(visited));
    vector<lo> bought;
    for (auto e : in4) {
        if (!bought.empty()) {
            cout << bought.size() << " : ";
            cout << bought.back() << nln;
            getch();

        }
        if (bought.size() == n)
            break;
        lo val = e.first, shop_idx = e.second.first, 
        person_idx = e.second.second;

        if (!visited[shop_idx] && cnt_visited == n-1)
            continue;
        
        if (received[person_idx])
            continue;
        received[person_idx] = true;
        bought.push_back(val);

        if (!visited[shop_idx]) {
            visited[shop_idx] = true;
            cnt_visited++;
        }
    }

    cout << bought.back() << nln;
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}