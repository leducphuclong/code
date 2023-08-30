#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long T;
	cin >> T;
	while (T--){
		long n;
		cin >> n;
		vector<long> a(n);
		for (auto &i : a)
			cin >> i;
		sort(a.begin(), a.end());
		bool check = 1;
		
		if (a[0] != 1)
			check = 0;
		
		long sum = 1;
		for (int i = 1; i < n; ++i)
			if (a[i] > sum){
				check = 0;
				break;
			}
			else
				sum += a[i];

		if (check)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}