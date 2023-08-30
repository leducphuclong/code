#include<iostream>
#include<vector>
#include<map>

#define long long long
#define nln '\n'

using namespace std;


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	map<long, long> cnt;
	while (n--){
		long x;
		cin >> x;
	}
	vector<long> ftr((long)1e5+10, 1);
	for (long i = 2; i <= (long)1e5; ++i){
		cout << i << ": " << ftr[i-1] << nln;
		ftr[i] = i*ftr[i-1];
		cout << i << ": " << ftr[i] << nln;
	}
	cout << ftr[10000] << nln;
	return 0;
}