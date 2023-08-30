// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/* Theory of this problem
    ~ A graph has Eulerian Path only when It has either 0 or 2 odd vertices.
    ~ If there are 0 odd vertices, start anywhere. If there are 2 odd vertices,
    start at one of them.
    ~ Follow edges one at a time. If you have a choice between a bridge and a
    non-bridge, always choose the non-bridge.
    ~ Stop when you run out of edges.
*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

void solve() {
}

int main(int argc, char* argv[]) {
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
