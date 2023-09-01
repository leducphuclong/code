
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll n = s.size();
        ll check = 0;
        ll check1 = 0;
        ll check2 = 0;
        for(ll i = 0; i <n; i++) {
            if(s[i] == 'F') {
                check1 = 0;
                check2 = 1;
            }
            else if(s[i] == 'D' && check2 == 1) {
                check1++;
            }
            else {
                check++;
                break;
            }
            if(check1 > 2) {
                check++;
                break;
            }
        }


        if(check == 0) {
            yes;
        }
        else {
            no;
        }
    }
    return 0;
}