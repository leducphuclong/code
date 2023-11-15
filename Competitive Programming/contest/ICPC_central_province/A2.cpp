#include <bits/stdc++.h>
using namespace std;
//
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
    int max1, max2, max3;
    max1 = max2 = max3 = a[0];
    for(int i = 1; i < n; ++i){
        max1 = max(a[i], max1 + a[i]);
        max2 = max(max2, max1);
        max3 = max(max3, a[i]);
    }
    cout<<max2 - max3<<endl;
}