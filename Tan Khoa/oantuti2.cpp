#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

// Function to compute (x^y) % mod using iterative method
long long power(long long x, long long y, long long mod) {
    long long result = 1;
    x = x % mod;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return result;
}

// Function to compute modular inverse of a number using Fermat's Little Theorem
long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

// Function to compute n choose k % mod
long long combination(int n, int k, long long mod) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    // To optimize, compute the smaller factorial
    if (k > n - k) {
        k = n - k;
    }

    long long numerator = 1;   // This will store n*(n-1)*...*(n-k+1)
    long long denominator = 1; // This will store k!
    for (int i = 1; i <= k; ++i) {
        numerator = (numerator * (n - (k - i))) % mod;
        denominator = (denominator * i) % mod;
    }

    return (numerator * modInverse(denominator, mod)) % mod;
}

long long permutation(int n, int k, long long mod) {
    if (k > n) return 0;
    if (k == 0) return 1;

    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result = (result * (n - i)) % mod;
    }
    return result;
}

int main() {
    // freopen("in", "r", stdin);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;


    cout << combination(n, k, mod) * power(2, n-k, mod) % mod;

    return 0;
}
