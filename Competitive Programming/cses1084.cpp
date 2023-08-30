#include<iostream>
#include<algorithm>

using namespace std;

typedef int64_t lo;
#define nln '\n'

int main() {
    // Fast IO
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // Input
    lo n, m, k;
    cin >> n >> m >> k;
    lo r[n];
    for (lo i = 0; i < n; ++i)
        cin >> r[i];
    lo h[m];
    for (lo i = 0; i < m; ++i)
        cin >> h[i];
    // Solve
    sort(r, r+n);
    sort(h, h+m);
    lo sell = 0, person = 0, sold = 0;
    while (sell < m && person < n) {
        if (r[person] >= h[sell]-k && r[person] <= h[sell]+k)
            ++sold, ++sell, ++person;
        else if (r[person] < h[sell]-k)
            ++person;
        else if (r[person] > h[sell]+k)
            ++sell;
    }
    // Ouput
    cout << sold << nln;

    return 0;
}