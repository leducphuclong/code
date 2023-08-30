#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<string> a{""};
	for (char i : str)
		if (i-'0' >= 0 && i-'0' <= 9)
			a.back() += i;
		else
			if (a.back().size() != 0)
				a.push_back("");

	for (auto i : a)
		cout << i << ' ';
	cout << nln;

	return 0;
}