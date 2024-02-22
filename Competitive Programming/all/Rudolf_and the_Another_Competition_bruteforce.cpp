#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    freopen("Rudolf_and_the_Another_Competition.inp", "r", stdin);
    freopen("Rudolf_and_the_Another_Competition.ans", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while(ttt--){
        int n, m, h;
        cin >> n >> m >> h;
        pair<int, long long> rud;
        int ans = 1;
        for(int i = 0; i < n; i++){
            vector<int> cur(m);
            for(int j = 0; j < m; j++){
                cin >> cur[j];
            }
            std::sort(cur.begin(), cur.end());
            int task_cnt = 0;
            long long penalty = 0, sum = 0;
            for(int j = 0; j < m; j++){
                if (sum + cur[j] > h) break;
                sum += cur[j];
                penalty += sum;
                task_cnt++;
            }
            if (i){
                if (make_pair(-task_cnt, penalty) < rud) ans++;
            } else rud = {-task_cnt, penalty};
        }
        cout << ans << '\n';
    }
    return 0;
}