#include<iostream>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

bool check(vector<long> a, long k, long m)
{
	long cnt = 1, s = 0;
	for (auto i : a){
		if (s+i <= m)
			s +=i;
		else{
			cnt++;
			s = i;
		}
		if (cnt > k)
			return 0;
	}
	return 1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("bai3truong.inp", "r", stdin);
	long n, k;
	cin >> n >> k;
	vector<long> a(n);
	long rig = 0;
	for (auto &i : a){
		cin >> i;
		rig += i;
	}

	long lef = *max_element(a.begin(), a.end()), res = -1;
	while (lef <= rig){
		long mid = (lef+rig)/2;
		if (check(a, k, mid))
			res = mid, rig = mid-1;
		else
			lef = mid+1;
	}

	cout << res << nln;

	return 0;
}