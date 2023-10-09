#include <iostream>

using namespace std;

#define nln '\n'
#define int long long

const int N = 5e6;
const int mod = 998244353;

int min_dvs[N+1]; bool exist[N+1];

void get_min_dvss() {
    // Eratosthenes sieve
    for (int i = 0; i <= N; i += 2)
        min_dvs[i] = 2;

    min_dvs[1] = 1;

    for (int i = 3; i <= N; i += 2) {
        if (min_dvs[i] == 0)
            min_dvs[i] = i;
        for (int j = i*i; j <= N; j += 2*i)
            if (min_dvs[j] == 0)
                min_dvs[j] = min_dvs[i];
    }
}

int Euler_totient(int n) {
    int res = n;
    while (n > 1) {
        int d = min_dvs[n];
        if (!exist[d])
            res -= res/d;
        while (n % d == 0)
            n /= d;
    }
    return res;
}

signed main() {
    // freopen("in", "r", stdin);
    get_min_dvss();
    int a, b;
    cin >> a >> b;
    int f_a = Euler_totient(a), res = 0;
    // Mark the prime divisors of a
    while (a > 1)
        exist[min_dvs[a]] = true,
        a /= min_dvs[a];
    // Sum up
    for (int x = 1; x <= b; ++x)
        res += f_a*Euler_totient(x), res %= mod;
    cout << res << nln;
    return 0;
}