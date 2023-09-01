#include<bits/stdc++.h>
using namespace std;
long long a[1000006];
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("icecream.txt","r",stdin);
    long long n,k;
    cin>>n>>k;
    int M=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]>M) M=a[i];
    }
 
    double l=0,r=M;
 
    while(l<=r && abs(l-r)>=1e-8){
        double m=(l+r)/2;
        long long res=0;
        for (int i=0;i<n;i++) res+=a[i]/m;
        if (res==k){
            l=m;
            break;
        }
        else if (res>k) l=m;
        else r=m;
        //cout<<res<<"---\n";
    }
    cout <<     
    //cout<<l<<" "<<r<<endl;
    //if (l!=0){
    double res=1e+12;
    for (int i=0;i<n;i++){
        long long te=max(a[i]/l,a[i]/(l-0.00000001));
        double p=a[i];
        p/=te;
        if (p<res) res=p;
        //cout<<te<<"--\n";
    }
    printf("%0.2f",res);

 
}