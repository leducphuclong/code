#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;   cin >> n >> m;
    string ps[n];
    for (int i = 0; i < n; i++)
        cin >> ps[i];

    int ans = 0, cur = 0;
    for (int d = 0; d < m; d++) {
        bool free = 1;
        for (int i = 0; i < n; i++)
            free &= ps[i][d] == 'o';
        if (free)
            cur++;
        else
            ans = max(ans, cur), cur = 0;
    }
    ans = max(ans, cur);
    cout << ans << endl;
    return 0;
}