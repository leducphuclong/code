// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define lo int64_t
#define nln '\n'

using namespace std;

int find_pos_off_max(vector<lo> &a, lo n){
	lo pst = 0, mav = 0;
	for (int i = n-1; i >= 0; --i)
		if (a[i] > mav){
			mav = a[i];
			pst = i;
		}
	return pst;
}

void solve() {
	lo n;
	cin >> n;
	vector<lo> a(n), b(n), c, d;
	lo pma = -1, pmb = -1, mxa = 0, mxb = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i){
		c.push_back(min(a[i], b[i]));
		d.push_back(max(a[i], b[i]));
	}
	if (find_pos_off_max(c, n) == n-1 && find_pos_off_max(d, n) == n-1)
		cout << "Yes";
	else
		cout << "No";
	cout << nln;
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
