#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    int n, m, k;        cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        string s;cin>>s;
        int a[m]={0};
        for(int j=0; j<m; j++){
            if(s[j] == 'x'){
                s[j] = 1;
            }
            if(s[j] == '.'){
                s[j] = 0;
             }
             if(s[j]=='#'){
                s[j]=100;
             }
}   int iddich=-1;
        for(int idx=0; idx<m; idx++){
            if(a[idx] ==1){
                iddich=idx;
            }
    }   
    if(iddich==-1){
        continue;
    }
    for(int idv=iddich;idv<=iddich+2*v;idv++){
        if(idv+2*v+1>iddich+v-1){
            break;
        }

    }
}
