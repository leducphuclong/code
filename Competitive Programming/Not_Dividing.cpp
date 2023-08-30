// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define lo int64_t
#define nln '\n'

using std::cout, std::cin, std::vector;

void solve() {
	lo n, x;
	cin >> n;
	vector<lo> arr(n+1, 0);
	for (lo i = 1; i <= n; ++i){
		cin >> arr[i];
		arr[i]++;
	}
	for (lo i = 2; i <= n; ++i){
		if (arr[i] % arr[i-1] == 0)
			arr[i]++;
		}
	}
	for (lo i = 1; i <= n ;++i)
		cout << arr[i] << ' ';
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
