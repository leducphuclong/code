// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define lo int64_t
#define nln '\n'

using std::cout, std::cin;

void solve() {
	lo l, r;
	cin >> l >> r;
	lo dmx = 0, res = l;
	for (lo x = l; x <= r; ++x){
		lo miv = 9, mav = 0, t = x;
		while (t > 0){
			if (t%10 > mav)
				mav = t%10;
			if (t%10 < miv)
				miv = t%10;
			t /= 10;
		}
		if (mav-miv > dmx){
			dmx = mav-miv;
			res = x;
		}
		if (dmx == 9)
			break;
	}
	cout << res << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
  return 0;
}
