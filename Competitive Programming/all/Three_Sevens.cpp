// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <iostream>
#include <vector>
#include <map>

#define lo int64_t
#define nln '\n'

using std::cout, std::cin, std:: map, std::vector;

void solve() {
	lo n;
	cin >> n;
	vector<vector<lo>> ltr(n), res(n);
	map<lo, bool> pld;
	for (int i = 0; i < n; ++i){
		lo d;
		cin >> d;
		while (d--){
			lo x;
			cin >> x;
			ltr[i].push_back(x);
		}
	}

	for (int day = n-1; day >= 0; --day){
		for (auto ppl : ltr[day])
			if (!pld[ppl]){
				res[day].push_back(ppl);
				pld[ppl] = 1;
			}
		if ((int)(res[day].size()) == 0){
			cout << -1 << nln;
			return;
		}		
	}

	for (long day = 0; day < n; ++day)
		cout << res[day][0] << ' ';
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
