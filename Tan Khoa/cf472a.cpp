#include <iostream>

using namespace std;

#define nln '\n'

int main() {

    // Sieve
    const long long N = int(1e4) + 5;
    bool is_prime[N];
    for (int i = 0; i < N; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < N; ++i) {
        if (is_prime[i] == false)
            continue;
        for (int j = i*i; j < N; j += i)
            is_prime[j] = false;
    }
    // Main
    long long n;
    cin >> n;
    long long ans = -1;
    for (long long m = 1; m <= 1000; ++m)
        if (is_prime[m*n+1] == false) {
            ans = m;
            break;
        }

    cout << ans << nln;

    return 0;
}

