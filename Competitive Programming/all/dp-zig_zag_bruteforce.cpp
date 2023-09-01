#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
 
//#include <functional>
//#include <map>
//#include <set>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <list>
 
using namespace std;
 
class ZigZag {
  public:
  int longestZigZag(vector <int> sequence) 
  {
    if(sequence.size() == 1) return 1;
    vector<int> v(sequence.size()-1);
    for(int i=1;i<sequence.size();i++)
    {
      v[i-1] = sequence[i] - sequence[i-1];
    }
    //    dir is first nonzero
    int ii=0;
    while( ii < v.size() && v[ii] == 0)
    ii++;
    if(ii == v.size()) return 1;
    int dir = v[ii];
    int len = 2;
    for(int i=ii+1;i<v.size();i++)
    {
      if(v[i] * dir < 0)
      {
        dir *= -1;  
        len++;
      }
    }
    return len;
  }
};
 
// Powered by PopsEdit

int main() {
  freopen("dp-zig_zag.inp", "r", stdin);
  freopen("dp-zig_zag.ans", "w", stdout);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
      cin >> i;
    ZigZag Z;
    cout << Z.longestZigZag(arr) << endl;
  }
  return 0;
}