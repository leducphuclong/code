#include <bits/stdc++.h>
//#define int long long
//#define double long double
#define Task "test"
#define READFILE freopen(Task".INP", "r", stdin)
#define WRITEFILE freopen(Task".OUT", "w", stdout)
#define double long double
#define oo 1e18
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define fi first
#define se second
#define watch(x) cout << (#x) << " = " << x << endl
#define debug(x) cout << (#x) << " = " << x << endl
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define endl '\n'
#define max3(a,b,c) max(max(a, b), c)
#define max4(a,b,c,d) max(max(a, b), max(c, d))
#define min4(a,b,c,d) min(min(a, b), min(c, d))
#define debug4(a,b,c,d) watch(a);watch(b);watch(c);watch(d)
#define ever (;true;)
#define maxn 505

#define PI 3.141592654

using namespace std;

typedef pair < int, int > ii;
typedef pair < int, ii > iii;
typedef pair < ii, ii > iiii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;
typedef vector < iii > viii;
typedef vector < vii > vvii;
typedef vector < iiii > viiii;
typedef vector < vvi > vvvi;

const int MOD = 998244353;
const int Base = 374;
const int _BaseDigit = 6;
const int _Base = 1e6;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

const int N = 1e6 + 5;
const int MN = 1e4 + 5;
const int BlockSize = 447;
const int MAXBIT = 20;

int n, l, r;
int a[N];
long long pre[N];

void init(){
    FAST;
    if (fopen(Task".inp", "r")){
        READFILE;
        WRITEFILE;
    }
}

double Get(int pos, double k){
    return pre[pos] - k * pos;
}

bool check(double k){
    deque < double > dq;
    for (int i = 1; i <= n; ++i){
        if (i >= l){
            double trc = Get(i - l, k);
            while (dq.size() && Get(dq.back(), k) > trc) dq.pop_back();
            dq.pb(i - l);
        }
        if (dq.size() && dq.front() < i - r) dq.pop_front();
        if (i >= l){
            double Min = Get(dq.front(), k);
            if (Min <= Get(i, k)) return 1;
        }
    }
    return 0;
}

signed main(){
    init();
    cin >> n >> l >> r;
    //n = ReadInt();
    //l = ReadInt();
    //r = ReadInt();
    double lo = 1e9, hi = -1e9;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        //a[i] = ReadInt();
        pre[i] = pre[i-1] + a[i];
        hi = max(hi, (double)a[i]);
        lo = min(lo, (double)a[i]);
    }
    check(2);
    while (hi - lo > 1e-6){
        double mid = (lo+hi)*0.5;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << setprecision(4) << fixed << lo;
    return 0;
}
