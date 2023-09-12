#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define ins insert
#define btpc __builtin_popcount
#define btclz __builtin_clz

#define sz(x) (int)(x.size());
#define all(x) x.begin(), x.end()
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;
const int N = 3e5 + 10;

ll a[N];
vector<int> pos[N];

void solve() {
    int n; cin >> n;

    vector<ll> val;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        val.pb(a[i]);
    }

    sort(all(val)); val.resize(unique(all(val)) - val.begin());
    for (auto v : val)
        cout << v << ' ';
    cout << endl;
    return;

    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(all(val), a[i]) - val.begin() + 1;
        pos[a[i]].pb(i);
    }

    int q; cin >> q;
    int s = 0;
    while(q--) {
        char c; cin >> c;
        if(c == 's') {
            int x; cin >> x;
            s += x;
            if(s >= n) s -= n;
            if(s <=-n) s += n;
        } else {
            ll x; cin >> x;
            int d = lower_bound(all(val), x) - val.begin() + 1;
            if(d > val.size() || val[d - 1] != x) {
                cout << -1 << '\n';
                continue;
            }

            x = d;

            int f = (s >= 0 ? s : n + s);
            int ans = (pos[x][0] + f - 1) % n + 1;
            int l = 0, r = pos[x].size() - 1;
            int base = ans;
            while(l <= r) {
                int mid = (l + r) >> 1;
                int b = (pos[x][mid] + f - 1) % n + 1;
                if(b < base) {
                    minimize(ans, b);
                    r = mid - 1;
                } else l = mid + 1;
            }

            cout << ans << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("in.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
}