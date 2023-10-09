#include <iostream>
#include <map>
#include <vector>
#include <conio.h>

using namespace std;

#define nln '\n'
#define int long long

map<int, int> min_dvs;

void get_min_dvss(int n) {
    // Eratosthenes sieve
    for (int i = 0; i <= n; i += 2)
        min_dvs[i] = 2;
    min_dvs[1] = 1;

    for (int i = 3; i <= n; i += 2) {
        if (min_dvs[i] == 0)
            min_dvs[i] = i;
        for (int j = i*i; j <= n; j += 2*i)
            if (min_dvs[j] == 0)
                min_dvs[j] = min_dvs[i];
    }
}

vector<int> factorize(int n) {
    vector<int> f;
    while (n > 1) {
        if (f.empty() || min_dvs[n] != f.back())
            f.push_back(min_dvs[n]);
        n /= min_dvs[n];
    }
    return f;
}

int ETF(int n) {
    int res = n;
    // Find min divisors of each number from 1 -> n
    get_min_dvss(n);
    // Find Euler's Totient
    while (n > 1) {
        int d = min_dvs[n];
        res -= res/d;
        while (n % d == 0)
            n /= d;
    }
    return res;
}

signed main() {
    int n;  cin >> n;
    cout << ETF(n) << nln;
    return 0;
}