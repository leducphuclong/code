#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define rep(i,n) for (int i=1;i <=int(n);i++)
#define ffor(i,n) for (int i=0;i <int(n);i++)  
#define sz(x) ((int) (x).size()) 
#define all(x) x.begin(),x.end()

ll solve (ll n , ll m , ll x) {
    ld halflen = (ld(x)*sqrt(3))/2 ;
    

    ll minneed = ceil(ld(n)/halflen);

    
    ll cntrow = 1;
    ld cur = x;
    while (cur < ld(m)) {
    
        cur += ld(x) * ld(1.5);
        cntrow++;
    }
    ll t2 = cntrow/2;
    ll t1 = cntrow - t2;

    if (minneed % 2 == 1) {
      
        ll h = minneed/2;

        return t1 * (h+1) + t2 * (h+1);
    }
    else {
       
        ll h = minneed/2;

        return t1 * (h) + t2 * (h+1);
    }

}
int main() {   
    freopen("latgach.inp", "r", stdin);
    freopen("latgach.ans", "w", stdout);
    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    ll t;cin >> t;
    while (t--){
        ll n , m , x ; cin >> n >> m >> x;
   
        cout << min( solve(n,m,x) , solve(m,n,x) ) << '\n';
    }

    return 0;
}
