

#include <bits/stdc++.h>
 
using namespace std;
int solve(int d, int r, int x){
    int cnt_edge=ceil((double) d/(x*sqrt(3)));
    int gach=2*cnt_edge+1;
    
    int cnt=d/(x*sqrt(3));
    double du=d-(double)cnt*x*sqrt(3);
    if (du>0&&du<=(double)x*sqrt(3)/2) gach--;
    int k=r/(3*x);
    du=r-k*3*x;
    int res=k*gach;
    if (du<=x){
        res+=cnt_edge;
    }
    else res+=gach;
    return res;
}
int main(){
    freopen("latgach.inp", "r", stdin);
    freopen("latgach.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--){
        int n,m,x;
        cin>>n>>m>>x;
        int a=solve(n,m,x);
        int b=solve(m,n,x);
        int res=min(a,b);
        
        cout<<res<<'\n';
    }
    return 0;

}

