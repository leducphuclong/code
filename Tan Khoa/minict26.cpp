#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    for (int i = 0; i < n; ++i)
        cnt[arr[i]]++;
        
    int ans = 0;
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
    	ans += it->second - 1;
	}
    
    cout << ans+1 << endl;
    
    return 0;
}
