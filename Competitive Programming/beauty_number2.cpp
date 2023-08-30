#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

const long MOD = 1e9+7;

using namespace std;

int main()
{
	//Input
	cin.tie(0)->sync_with_stdio(0);
	freopen("beauty_number.inp", "r", stdin);
	//freopen("beauty_number.out", "w", stdout);
	string l, r;
	getline(cin, l, nln);
	getline(cin, r, nln);
	while (l.size() < r.size())
		l = ' ' + l;
	cout << l.size() <<  " ~ " << r.size() << nln;
	string res = r;

	long i = 0;
	while (i < (long)r.size()){
		if (r[i]-'0'-1 >= l[i]-'0'){
			if (r[i]-'0' >= 8){
				bool check = 0;
				for (long j = i+1; j < (long)r.size(); ++j)
					if (r[j]-'0' < 9)
						check = 1;
			}
		}
	}

	cout << res << nln;
	return 0;
	long mul = 1;
	for (auto i : res)
		mul *= i-'0', mul %= MOD;
	cout << mul << nln;

	return 0;
}