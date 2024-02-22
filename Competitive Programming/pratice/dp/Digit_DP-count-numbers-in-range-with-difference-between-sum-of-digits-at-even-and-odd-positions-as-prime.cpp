#include <iostream>
#include <cstring>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

#define int long long
#define nln '\n'

const int N = 1e6+2;
const bool TIGHT = 2;
const int IDX = 19;
const int ODD = 1e3+2;
const int EVE = 1e3+2;

// Global Variables
bool is_prime[N];
int dp[IDX][EVE][ODD][TIGHT];
vector<int> digits;
// End Declaration

// Eratosthenes sieve
void Eratosthenes_sieve() {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;

    for (int i = 4; i < N; i += 2)
        is_prime[i] = false;

    for (int i = 3; i < N; i += 2) {
        if (!is_prime[i])
            continue;
        for (int j = i*i; j < N; j += 2*i)
            is_prime[j] = false;
    }
}

void get_digits(int n) {
    digits.clear();
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    digits.push_back(0);
    reverse(digits.begin(), digits.end());
}

int cal(int idx, int eve, int odd, bool tight) {
    if (idx == digits.size()) {
        if (digits.size() & 1)
            swap(odd, eve);
        return eve > odd && is_prime[eve-odd];
    }

    if (dp[idx][eve][odd][tight] != -1)
        return dp[idx][eve][odd][tight];

    int cnt = 0;
    int lim = (tight) ? digits[idx] : 9;
    for (int v = 0; v <= lim; ++v) {
        bool next_tight = (v == lim) ? tight : false;
        if (idx & 1)
            cnt += cal(idx+1, eve, odd+v, next_tight);
        else
            cnt += cal(idx+1, eve+v, odd, next_tight);
    }
    return dp[idx][eve][odd][tight] = cnt;
}

int calculate(int n) {
    if (n == 0)
        return 0;
    get_digits(n);
    memset(dp, -1, sizeof dp);
    return cal(1, 0, 0, true);
}

void solve() {
    int l, r;       cin >> l >> r;
    cout << calculate(r) - calculate(l-1) << nln;
}

signed main() {
    freopen("in", "r", stdin);
    Eratosthenes_sieve();
    int tc;     cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}