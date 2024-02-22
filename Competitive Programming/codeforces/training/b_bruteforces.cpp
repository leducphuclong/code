#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
int main() 
{
    int n;
    cin>>n;
    map<string, int> m1, m2, m3;
    for(int i = 0; i < n; ++i){
      string st;
      cin>>st;
      string sub4 = st.substr(2, 4);
      string sub2 = st.substr(4, 2);
      ++m1[st];
      ++m2[sub4];
      ++m3[sub2];
    }
    ++m1["0"];
    ++m2["0"];
    int res = 0;
    const int n1 = 300'000;
    const int n2 = 4'000;
    const int n3 = 500;
    int money = 0;
    for(auto i:m1){
      money = 0;
pair<string, int> p2, p3;
      if(i.ft != "0"){
      money = money + n1*i.sd;
      p2.ft = i.ft.substr(4, 2);
      p2.sd = m3[p2.ft];
      }
      int money2 = money;
      for(auto j:m2){
        money = money2;
        if(j.ft != "0")
        {
        if(j.ft.substr(2, 2) != p2.ft){
          money = money + j.sd*n2;
          p3.ft = j.ft.substr(2, 2);
          p3.sd = m3[p3.ft];
        }
        else money = money + (j.sd - p2.sd)*n2;
        }
        for(auto &z:m3){
          if(z.ft != p2.ft){
            if(z.ft == p3.ft){
              z.sd = (z.sd - p3.sd);
            }
          }
          else{
            if(z.ft != p3.ft){
              z.sd = z.sd - p2.sd;
            }
            else{
              z.sd = z.sd - p2.sd - p3.sd;
            }
          }
        }
        int val1 = 0, val2 = 0, val3 = 0;
        for(auto z:m3){
          if(val1 < z.sd){
            val3 = val2;
            val2 = val1;
            val1 = z.sd;
          }
          else if (val2 < z.sd){
            val3 = val2;
            val2 = z.sd;
          }
          else if(val3 < z.sd){
            val3 = z.sd;
          }
        }
        money = money + (val1 + val2 + val3)*n3;
        res = max(res, money);
        for(auto &z:m3){
          if(z.ft != p2.ft){
            if(z.ft == p3.ft){
              z.sd = (z.sd + p3.sd);
            }
          }
          else{
            if(z.ft != p3.ft){
              z.sd = z.sd + p2.sd;
            }
            else{
              z.sd = z.sd + p2.sd + p3.sd;
            }
          }
          
        }
      }
    }
    cout<<res<<endl;
}