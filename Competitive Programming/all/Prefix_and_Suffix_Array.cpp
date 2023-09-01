// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define lo int64_t
#define nln '\n'

using std::cout, std::cin, std::string, std::map, std::vector;

void solve() {
	lo n;
	cin >> n;
	cin.ignore();		
	string s;
	getline(cin, s, '\n');
	vector<string> str({""});
	for (auto i : s)
		if (i != ' ')
			str.back() += i;
		else
			str.push_back("");
	map<int, string> sav;
	for (auto i : str){
		lo l = i.size();
		if (sav[l] == "")
			sav[l] = i;
		else{
			reverse(i.begin(), i.end());
			if (sav[l] != i){
				// cout << sav[l] << " != " << i << nln;
				cout << "No" << nln;
				return;
			}
		}
	}
	cout << "Yes" << nln;
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
