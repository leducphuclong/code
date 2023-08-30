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
	if ((long)l.size() < (long)r.size()){
		long i = 0;
		while (i < (long)r.size()){
			if (r[i] > r[i+1] || (r[i] == r[i+1] && r[i] != '8' && r[i] != '9'))
				break;
			++i;
		}
		
		if (i < (long)r.size()-1){
			for (long j = 0; j < i; ++j)
				res[j] = r[j];

			res[i] = (((r[i]-'0')-1)+'0');

			for (long j = i+1; j < (long)r.size(); ++j)
				res[j] = (9+'0');
		}
	}
	else{
		cout << "hi" << nln;
		long i = 0;
		while (i < (long)r.size()-1){
			if (((r[i] == r[i+1] && r[i] != '8' && r[i] != '9')) && ((r[i]-'0')-1) >= (l[i]-'0'))	
				break;
			++i;
		}

		if (i < (long)r.size()-1){
			for (long j = 0; j < i; ++j)
				res[j] = r[j];

			res[i] = (((r[i]-'0')-1)+'0');

			for (long j = i+1; j < (long)r.size(); ++j)
				res[j] = (9+'0');
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