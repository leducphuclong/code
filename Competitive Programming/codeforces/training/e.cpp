#include <bits/stdc++.h>

#define for_(n) for (int i = 0;i < n;i++)
#define ll long long
#define for__(a,b) for (int i = a;i < b;i++)
#define en "\n"

using namespace std;

void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    ll count = 0;
    vector<int> score(n,1);
    while (score[0] <= k){
        int sum = 0;
        for_(n) sum+= score[i];
        if (sum > p) count++;
        score[n-1]++;
        for (int i = n-1;i > 0;i--){
            if (score[i] > k){
                score[i] = 1;
                score[i-1]++;
            }
        }
    }
    cout << count << en;
}

int main(){
    solve();
    return 0;
}