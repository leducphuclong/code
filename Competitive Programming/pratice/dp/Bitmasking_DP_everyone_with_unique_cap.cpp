#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <limits>
#include <conio.h>
#include <bitset>

using namespace std;

#define nln '\n'

const int MOD = 1000000007;

// Global variables declaration
long long n, dp[(1 << 10)][101];
vector<long long> caps_list[101];
bool wore[10];

// End declaration

long long memoization(long long mask, int idx) {
    if (mask == ((1 << n)-1)) 
        return 1ll;

    if (idx > 100)    
        return 0ll;

    if (dp[mask][idx] != -1)
        return dp[mask][idx];

    long long ways;
    ways = memoization(mask, idx+1);
    for (auto v : caps_list[idx]) {
        if (mask & (1 << v))
            continue;
        ways += memoization(mask | (1 << v), idx+1);
        ways %= MOD;
    }
    return dp[mask][idx] = ways;
}

int recursion(int idx) {
    bool all_wearing_cap = true;
    for (int i = 0; i < n; ++i)
        if (wore[i] == false)
            all_wearing_cap = false;
    if (all_wearing_cap)
        return 1;

    if (idx > 100)
        return 0;

    int ways = recursion(idx+1);
    for (auto c : caps_list[idx]) {
        if (wore[c] == true)
            continue;
        wore[c] = true;
        ways += recursion(idx+1);
        ways %= MOD;
        wore[c] = false;
    }

    return ways;
}

int tabulation() {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 1; j <= 100; ++j) {
            dp[i][j] += dp[i][j-1], dp[i][j] %= MOD;
            for (auto c : caps_list[j]) {
                if (!i & (1 << c))
                    continue;
                dp[i][j] += dp[i ^ (1 << c)][j-1], dp[i][j] %= MOD;
            }
        }
    }
    return dp[(1 << n)-1][100];
}

void countWays_memoization() {
    memset(dp, -1, sizeof dp);
    cout << "By memoization, the answer is " << memoization(0, 1) << nln;
}

void countWays_recursion() {
    cout << "By recursion, the answer is: " << recursion(1) << nln;
}

void countWays_tabulation() {
    cout << "By tabulation, the answer is: " << tabulation() << nln;
}

int main() {
    freopen("in", "r", stdin);
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
        string str, tmp;
        getline(cin, str);
        stringstream ss(str);
        while (ss >> tmp) {
            long long x;
            stringstream s; s << tmp;
            s >> x;
            caps_list[x].push_back(i);
        }
    }
    countWays_memoization();
    countWays_recursion();
    countWays_tabulation();
    return 0;
}