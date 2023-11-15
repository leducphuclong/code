#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define nln '\n'

int main() {
    // Fast IO
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // Sieve
    const int N = int(1e7) + 5;
    bool is_prime[N];   memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i < N; ++i) {
        if (is_prime[i] == false)
            continue;
        for (int j = i*i; j < N; j += i)
            is_prime[j] = false;
    }
    // Solve
    int n;      cin >> n;
    vector<int> res;
    for (int i = 2; i <= n-2; ++i)
        if (is_prime[i] == true && is_prime[i+2] == true)
        res.push_back(i);
    // Output
    cout << res.size() << endl;
    for (auto v : res)
        cout << 2 << ' ' << v << endl;

    return 0;
}
