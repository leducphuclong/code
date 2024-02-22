#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#include <bitset>
#include <conio.h>

using namespace std;

#define nln '\n'

const int n=4; // Number of the places want to visit

 //Next distan array will give Minimum distance through all the position
int dist[n][n] = {                
                    {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}
                };

int dp[(1 << n)][n];

int TSP(int status, int pst) {
    // already visited all places, so comback to first place. (0th place)
    if (status == (1 << n)-1) 
        return dist[pst][0];
    // If this sub problems had the solution, we just turn it out.
    if (dp[status][pst] != -1)
        return dp[status][pst];
    int cost = INT_MAX;
    for (int idx = 0; idx < n; ++idx) {
        if (!(status & (1 << idx))) {
            int cost_val = dist[pst][idx] + TSP(status ^ (1 << idx), idx);
            cost = min(cost, cost_val);
        }
    }
    return dp[status][pst] = cost;
}

void TST_by_memoization() {
    memset(dp, -1, sizeof dp);
    cout<<"Minimum Distance Travelled by memoization is "<< TSP(1, 0) << nln;
}

void trace_back_to_find_the_route() {
    int current_state = ((1 << n)-1), current_place = 0;
    current_state ^= 1; // flip the 0th bit, implie that 0th bit is already used
    vector<int> cycle;
    for (int t = 1; t <= n-1; ++t) {
        int idx = -1, min_d = INT_MAX;
        for (int i = 1; i < n; ++i)
            if ((1 << i) & current_state) {
                int d = dist[current_place][i] + dp[current_state][i];
                if (d < min_d)
                    min_d = d, idx = i;                
            }
        // cout << "current_state: " << bitset<10>(current_state) << nln;
        // cout << "idx: " << idx << nln;
        current_state ^= (1 << idx);
        // cout << "moded current_state: " << bitset<10>(current_state) << nln;

        current_place = idx;
        cycle.push_back(idx);
    }
    cycle.push_back(0);
    reverse(cycle.begin(), cycle.end());
    cycle.push_back(0);
    cout << "The route is: ";
    for (auto c : cycle)
        cout << c << ' ';
    cout << nln;
    int l = cycle.size();
    int total_cost = 0;
    for (int i = 0; i < l-1; ++i)
        total_cost += dist[cycle[i]][cycle[i+1]];
    cout << "Check total_cost: " << total_cost << nln;
}

void generate_subset(int status, int n, int k, vector<int> &ss) {
    if (k == 0) {
        ss.push_back(status);
        return;
    }
    if (n < 0)
        return;
    generate_subset(status, n-1, k, ss);
    generate_subset(status ^ (1 << n), n-1, k-1, ss);
}

void TST_by_tabulation() {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < n; ++i)
        dp[1 | (1 << i)][i] = dist[0][i];

    for (int qtt = 3; qtt <= n; ++qtt) {
        vector<int> ss;     generate_subset(0, n-1, qtt, ss);
        for (auto next_status : ss) {
            if (!(1 << 0 & next_status)) // if not include the 0 node
                continue;
            for (int end = 1; end < n; ++end) {
                if (!(next_status & (1 << end))) continue;
                int min_d = INT_MAX;
                for (int prev = 1; prev < n; ++prev) {
                    if (prev == end || !(next_status & (1 << prev))) continue;
                    int d = dp[next_status ^ (1 << end)][prev] + dist[prev][end];
                    if (d < min_d)
                        min_d = d;
                }
                dp[next_status][end] = min_d;
            }
        }
        // cout << "watch: " << nln;
        // cout << "size: " << ss.size() << nln;
        // cout << "qtt: " << qtt << nln;
        // for (auto s : ss)
        //     cout << bitset<4>(s) << nln;
        // getch();
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; ++i)
        ans = min(ans, dp[(1 << n)-1][i]+dist[i][0]);
    cout << "Minimum Distance Travelled by tabulation is: " << ans << nln;
}

int main(){
    TST_by_memoization();
    trace_back_to_find_the_route();
    TST_by_tabulation();
    trace_back_to_find_the_route();
    memset(dp, -1, sizeof(dp));
    trace_back_to_find_the_route();
    return 0;
}