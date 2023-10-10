#include <iostream>
#include <vector>
#include <conio.h>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define nln '\n'

const int N = 1e4+2, S = 1e4+2;

// Global Variables
int dp[N], n, a[] = {3, 5, 1, 1, 4, 3, 5, 1, 2, 3, 4, 3, 6, 5 };
vector<int> v[N]; 
bool vst[N];
// End Declaration

int calculate(int u) {
    if (dp[u] != -1)
        return dp[u];
    vst[u] = true;
    dp[u] = a[u-1];
    for (auto i : v[u])
        if (!vst[i])
            dp[u] = max(dp[u], a[u-1] + calculate(i));
    vst[u] = false;
    return dp[u]; 
}

signed main() 
{ 
    // number of nodes 
    n = 14;
    // create undirected edges 
    // initialize the tree given in the diagram 
    v[1].push_back(2), v[2].push_back(1); 
    v[1].push_back(3), v[3].push_back(1); 
    v[1].push_back(4), v[4].push_back(1); 
    v[2].push_back(5), v[5].push_back(2); 
    v[2].push_back(6), v[6].push_back(2); 
    v[3].push_back(7), v[7].push_back(3); 
    v[4].push_back(8), v[8].push_back(4); 
    v[4].push_back(9), v[9].push_back(4); 
    v[4].push_back(10), v[10].push_back(4); 
    v[5].push_back(11), v[11].push_back(5); 
    v[5].push_back(12), v[12].push_back(5); 
    v[7].push_back(13), v[13].push_back(7); 
    v[7].push_back(14), v[14].push_back(7); 
  
    // values of node 1, 2, 3....14 
    memset(dp, -1, sizeof dp);
    cout << calculate(1) << nln;
    cout << "OK" << nln;

    return 0; 
} 