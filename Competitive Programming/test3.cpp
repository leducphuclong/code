#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FOD(i, a, b) for (ll i = a; i > b; i--)
#define vi vector<ll>
#define vs vector<string>
#define vvi vector<vector<ll>>
#define vii vector<pair<ll, ll>>

bool multiTest = 0;

const ll maxN = ll(2e5 + 1);
const ll mod = ll(1e9 + 7);

void solved()
{
    ll n, q;
    cin >> n >> q;

    vi a(n);
    FOR(i, 0, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;

            if (binary_search(all(a), x) == 0)
            {
                ll p = upper_bound(all(a), x) - a.begin();
                if (p == a.size())
                    a.push_back(x);
                else
                    a[p] = x;
            }
        }
        else
        {
            ll l, r;
            cin >> l >> r;

            ll pl = lower_bound(all(a), l) - a.begin();
            ll pr = upper_bound(all(a), r) - a.begin();
            cout << pr - pl << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);

    ll tc;
    if (multiTest)
        cin >> tc;
    else
        tc = 1;
    while (tc--)
    {
        solved();
        cout << endl;
    }

    return 0;
}