/*
 * for m in [low, high], find m by binary search
 * for each b[i+1] = b[i] + a[i] - m
 * for r in [0, n]:
 *      if b[r] - b[x] >= 0:
 *          // x in [r-R, r-l]
 *          founded
 *
 * if founded:
 *      exist a number higher than m is answer possible
 *      inc low by m +1
 *      save m is current answer
 * else:
 *      dec high by m - 1
 * */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const double esp = 1e-6;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> a(n);
    for (int&x : a) cin >> x;
    int lower = a[0];
    int higher = a[0];
    for (int i = 1; i < n; ++i) {
        lower = min(lower, a[i]);
        higher = max(higher, a[i]);
    }
    double low = lower, high = higher;
    double ans = -1;
    while (fabs(high-low) > esp) {
        double m = low + (high-low)/2;
        vector <double> b(n+1);
        b[0] = 0;
        for (int i = 0; i < n; ++i) {
            b[i+1] = b[i] + a[i] - m;
        }
        deque<double> dq;
        int founded = 0;
        for (int right = l; right <= n && !founded; ++right) {
            while (!dq.empty() && right - dq.front() > r)
                dq.pop_front();
            while (!dq.empty() &&  b[dq.back()] >= b[right-l] && right >= l)
                dq.pop_back();
            if (right >= l)
                dq.push_back(right - l);
            double x = b[right] - b[dq.front()];
            if (x >= 0) founded = 1;
        }
        if (founded == 1) {
            low = m + esp;
            ans = m;
        } else {
            high = m - esp;
        }
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}
