// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define lo int64_t
#define nln '\n'

using std::cout, std::cin, std::vector, std::string, std::;

vector<string> rps = {">=", "<"};
lo l = 1, r = 1e6;

void solve() {
    lo cnt = 0;
    string str;
    while (1){
        ++cnt;
        lo m = round((l+r)/2.0);
        cout << m << endl;
        getline(cin, str, nln);
        if (str == rps[0])
            l = m;
        else
            r = m-1;
        if (l == r){
            cout << "! " << r << endl;
            break;
        }
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
