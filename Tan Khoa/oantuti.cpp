#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

// Function to compute factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to compute n choose k
long long combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    // To optimize, compute the smaller factorial
    if (k > n - k) {
        k = n - k;
    }

    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result *= n - (k - i);
        result /= i;
    }

    return result;
}

int main() {
    // freopen("in", "r", stdin);

    int n, k;   cin >> n >> k;
    string s;   cin >> s;


    cout << combination(n, k)*2*(n-k);
    
    return 0;
}
