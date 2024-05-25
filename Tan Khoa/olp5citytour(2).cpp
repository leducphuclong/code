#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nln '\n'

const int N = 4e5 + 5;
ll dp[N][35][2];
ll last[N], a[N];
int n, k;
map<ll,ll> mp;
ll dq(int index, int ticket, int used){
    if(index > n) return 0;
    ll &ans = dp[index][ticket][used];
    if(ans != -1) return ans;
    ans = 0;
    if(used){
        ans = max(ans, dq(index + 1, ticket, used));
        ans = max(ans, dq(index, ticket, 0) + a[index]);
    }
    else{
        if(last[index]){
            int pos = last[index];
            ans = max(ans, dq(pos, ticket, 0) + a[pos]);
        }
        if(ticket < k){
            ans = max(ans, dq(index + 1, ticket + 1, 1));
        }
    }
    return ans;
}
int main(){
    if (fopen("in", "r"))
        freopen("in", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> a[i];
        last[mp[i - a[i]]] = i;
        cout << "see: " << i - a[i] << nln;
        mp[i - a[i]] = i;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dq(i, 0, 0) + a[i]);
    }   
    cout << ans;
}
