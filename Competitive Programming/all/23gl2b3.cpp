// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define lo int64_t
#define nln '\n'

using std::cout, std::cin, std::vector;

void solve() {
    lo n, m;
    cin >> n >> m;
    vector<lo> sta(n), ppl(m);
    for (auto &i : sta)
        cin >> i;
    for (auto &i : ppl)
        cin >> i;

    

    for (auto x : ppl){
        lo lef = 0, rig = n-1, res = 0;
        while (lef <= rig){
            lo mid = (lef+rig) / 2;
            if (sta[mid] <= x){
                lef = mid+1;
                res = lef;
            }
            else{
                rig = mid-1;
            }
        }
        cout << res << nln;
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
  return 0;
}
