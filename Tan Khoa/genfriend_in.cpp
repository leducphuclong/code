#include <bits/stdc++.h>
#include <random>
using namespace std;
 
mt19937_64 rng(static_cast<long long>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()));

long long Rand(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main(int argc, char** argv) {
    freopen(argv[1], "w", stdout);

    long long n = Rand(1, 1e5);
    cout << n << endl;
    for (int i = 0; i < n-1; ++i) {
        cout << Rand(1, 1e9) << ' ';
    } cout << Rand(1, 1e9);
}