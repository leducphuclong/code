#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define read(a) int a;cin>>a
#define ll long long
#define vpii vector<pair<int,int>> 
//#define endl "\n"
const double Pi=3.141592653589793;
/* THE UNIVERSITY OF SCIENCEN AND TECHNOLOGY
          THE UNIVERSITY OF DA NANG */
vector<ll> v;
void createFib(){
    ll tmp1 = 1, tmp2 = 1;
    while(tmp2 <= 1e18){
        ll tmp = tmp2;
        tmp2 = tmp1 + tmp2;
        tmp1 = tmp;
        v.pb(tmp2);
    }
}
ll cnt;
vector<ll> v2;
ll deQuy(ll n, ll p){
    ll res = 0;
    for(ll i:v2){
        if(i <= p){
            if(n == i)  res+=1;
            else if(n%i == 0)res += deQuy(n/i, i);
        }
    }
    return res;
}
void solve(){
    ll n;
    cin>>n; 
    v2.clear();
    for(ll i:v){
        if(n%i == 0){
            v2.pb(i);
        }
    }
    cout<<deQuy(n, 1e9)<<endl;
}


int main() {
    freopen("in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    createFib();   
    int tc;
    cin>>tc;
    while(tc--)
    solve();

    
    return 0;
}