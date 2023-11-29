//Thống kê nguyên âm: WA
#include <bits/stdc++.h>

using namespace std;

int main() {
   string s;
   while(getline(cin, s)) {
       int dem = 0;
       for(int i = 0; i < s.length(); i++) {
           if(toupper(s[i]) == 'A' || toupper(s[i]) == 'E' || toupper(s[i]) == 'I' || toupper(s[i]) == 'O' || toupper(s[i]) == 'U' || toupper(s[i]) == 'Y')
               dem += 1;
       }
       cout << dem << endl; 
   }
   return 0;
}