// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant
const lo V = 1e6;

// Declare global variables.
vector<lo> prm, par, rnk, qtt;
lo n, mav = 0;   stack<lo> pars_edited, rnks_edited, qtts_edited;
// End of global variable declaration.

void precompute() {
    // Eratosthenes Sieve        
    lo v = round(sqrt(V));
    vector<bool> chk(v+1, true);
    chk[0] = chk[1] = false;
    for (lo i = 2; i <= round(sqrt(v)); ++i)
        for (lo j = 2*i; j <= v; j += i)
            chk[j] = false;
    // Push all prime numbers to prm vector
    for (lo i = 2; i <= v; ++i)
        if (chk[i] == true)
            prm.push_back(i);
}

bool is_prime(lo n) {
    if (n < 2) return false;
    for (lo i = 2; i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

class Disjoint_set {
    private:

    public:
    void Initialize() {
        rnk.resize(n+1, 0), par.resize(n+1, 0), qtt.resize(n+1, 1);
        for (lo i = 1; i <= n; ++i)
            par[i] = i;
    }

    lo Find(lo v) {
        if (par[v] == v)
            return v;
        lo p = Find(par[v]);
        par[v] = p;
        return par[v];
    }

    void Union(lo u, lo v) {
        lo par_u = Find(u), par_v = Find(v);
        if (par_u == par_v)
            return;
        if (rnk[par_u] < rnk[par_v]) {
            if (par[par_u] == u)
                pars_edited.push(par_u);
            par[par_u] = par_v;
            if (qtt[par_v] == 0)
                qtts_edited.push(par_v);
            qtt[par_v] += qtt[par_u];
            mav = max(mav, qtt[par_v]);
        } else {
            if (par[par_v] == v)
                pars_edited.push(par_v);
            // cout << u << " ~ " << v << nln;
            // cout << par_u << " ~ " << par_v << nln;
            // cout << "par_u: " << par_u << endl;
            par[par_v] = par_u;
            if (qtt[par_u] == 0)
                qtts_edited.push(par_u);
            qtt[par_u] += qtt[par_v];
            mav = max(mav, qtt[par_u]);
            if (rnk[par_u] == rnk[par_v]) {
                if (rnk[par_u] == 0)
                    rnks_edited.push(par_u);
                rnk[par_u]++;
            }
        }
    }

    void reset() {
        while (!rnks_edited.empty()) {
            rnk[rnks_edited.top()] = 0;
            rnks_edited.pop();
        }
        while (!pars_edited.empty()) {
            par[pars_edited.top()] = pars_edited.top();
            pars_edited.pop();
        }
        while (!qtts_edited.empty()) {
            qtt[qtts_edited.top()] = 1;
            qtts_edited.pop();
        }
        mav = 0;
    }

    lo Biggest_set() {
        lo mav = 0;
        map<lo, lo> cnt;
        for (lo i = 1; i <= n; ++i) {
            lo pi = Find(i);
            cnt[pi]++;
            mav = max(mav, cnt[pi]);
        }
        return mav;
    }
};

void solve() {
    // Input
    cin >> n;
    set<lo> sav;
    vector<lo> val(n+1);
    for (lo i = 1; i <= n; ++i) {
        cin >> val[i];
        sav.insert(val[i]);
    }
    vector<pair<lo, lo>> edges(n-1);
    for (auto &p : edges)
        cin >> p.first >> p.second;
    // SOLVE
    // Special case
    if (val[1] == 1 and sav.size() == 1) {
        cout << 0 << nln;
        return;
    }
    // Process the latter case
    map<lo, vector<pair<lo, lo>>> frts;
    for (auto e : edges) {
        lo g = __gcd(val[e.first], val[e.second]);
        if (is_prime(g)) {
            frts[g].push_back({e.first, e.second});
            continue;
        }

        for (auto p : prm) {
            if (g % p == 0) {
                frts[p].push_back({e.first, e.second});
            }
        }
    }
    // Find the ans by disjoint set
    lo ans = 1;
    Disjoint_set dsu;
    dsu.Initialize();
    for (lo v = 2; v <= V; ++v) {
        if (frts[v].empty())
            continue;
        // cout << "v:  " << v << nln;
        for (auto e : frts[v]) {
            dsu.Union(e.first, e.second);
        }
        ans = max(ans, mav);
        dsu.reset();
    }
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}