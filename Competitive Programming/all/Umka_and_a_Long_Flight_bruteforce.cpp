#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;

int fib[MAXN];

void build() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        fib[i] = fib[i - 2] + fib[i - 1];
}

bool solve(int n, int x, int y) {
    if (n == 1) return true;
    if (fib[n - 1] <= y && y < fib[n])
        return false;
    if (fib[n] <= y)
        y -= fib[n];
    return solve(n - 1, y, x);
}

int main() {
    freopen("Umka_and_a_Long_Flight.inp", "r" ,stdin);
    freopen("Umka_and_a_Long_Flight.ans", "w", stdout);
    int t; cin >> t;
    build();
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        cout << (solve(n, --x, --y) ? "YES" : "NO") << '\n';
    }
}
