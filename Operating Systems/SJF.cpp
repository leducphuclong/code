#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define nln '\n'
#define int long long

signed main(int argc, char **argv) {
    // Get Data
    freopen("SJF.inp", "r", stdin);
    int n;  cin >> n;
    pair<int, int> process[n];
    for (int i = 0; i < n; ++i)
        cin >> process[i].first;
    for (int i = 0; i < n; ++i)
        cin >> process[i].second;
    // Short Job First Algorithm
    sort(process, process + n);
    bool enter[n];
    memset(enter, false, sizeof enter);
    int curr_time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> que;
    que.push({2, 3}); que.push({1, 4});
    cout << que.top().first << ' ' << que.top().second << nln;
    for (int i = 0; i < n; ++i) {
    }
    return 0;
}