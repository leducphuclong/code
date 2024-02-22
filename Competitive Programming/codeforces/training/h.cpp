#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fl float
#define db double
#define se second
#define fi first
#define MAX 8
#define nl endl
#define mod1 (ll)(998244353)
#define mod2 (ll)(1000000007)
#define pb push_back
#define pi 3.141592653589793
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define le length()
#define sz size()
using namespace std;
// string mainstr = "abcdefghijklmnopqrstuvwxyz";
ll powMod (int a,int b) {
    ll res = 1;
    for( ; b > 0; b >>= 1, a = a * a % mod1 ){
        if(b & 1) res = res * a % mod1;
        cout << res << nl;
    }
    return res;
}
void solve()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll mn = mod2;
    for(ll i = 1; i <= sqrt(c); i ++){
        if(c % i == 0)
        {
            if(d%i!=0 && i%a==0 && i%b!=0){
                mn = min(mn, i);
            }
            ll ii = c/i;
            if(d%ii!=0 && ii%a==0 && ii%b!=0){
                mn = min(mn, ii);
            }
        }
        
    }
    if(mn != mod2) cout << mn << nl;
    else cout << -1 << nl;
}

int main()
{
//        freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    // prime();
    // int test;
    // cin>>test;
    // while(test--){
    solve();
    // }
    return 0;
}