#include <bits/stdc++.h>
#include <random>

using namespace std;

#define nln '\n'
typedef int64_t lo;

mt19937_64 rng(static_cast<long long>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()));

long long Rand(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}


int main(int argc, char** argv) {
    freopen(argv[1], "w", stdout);
    lo n = Rand(1, static_cast<lo>(1e4));
    cout << n << nln;
    for (lo i = 0; i < n; ++i)
        cout << Rand(1, static_cast<lo>(1e9)) << ' ' << Rand(1, static_cast<lo>(1e9)) << endl;
    return 0;
}