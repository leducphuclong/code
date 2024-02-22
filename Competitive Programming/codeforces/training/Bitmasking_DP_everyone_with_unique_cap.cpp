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
long long n, dp[(1 << 10)][102];
vector<long long> caps_list[102];
// End declaration

long long countWaysUltil(long long mask, int idx) {
    if (mask == ((1 << n)-1)) 
        return 1ll;

    if (idx > 100)    
        return 0ll;

    if (dp[mask][idx] != -1)
        return dp[mask][idx];

    long long ways;
    ways = countWaysUltil(mask, idx+1);
    for (auto v : caps_list[idx]) {
        if (mask & (1 << v))
            continue;
        ways += countWaysUltil(mask | (1 << v), idx+1);
        ways %= MOD;
    }

    return dp[mask][idx] = ways;
}

void countWays() {
    memset(dp, -1, sizeof dp);
    cout << "The answer: " << countWaysUltil(0, 1) << nln;
    cout << "The table is: ";
    for (int i = 0; i < n; ++i)
        cout << dp[1 << 10 - 1][i] << ' ';
    cout << nln;
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
    countWays();
    return 0;
}