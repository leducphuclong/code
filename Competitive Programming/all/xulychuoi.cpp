#include<iostream>
#include<cstring>
#include<cctype>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	getline(cin, str, nln);
	while (str[0] == ' ')
		str.erase(str.begin());
	while (*(str.end()-1) == ' ')
		str.erase(str.end()-1);
	for (long i = 0; i < (long)str.size()-1; ++i)
		if (str[i] != ' ' && str[i+1] == ' ')
			while (str[i+2] == ' ')
				str.erase(str.begin()+i+2);
	str[0] = toupper(str[0]);
	for (long i = 1; i < (long)str.size(); ++i)
		str[i] = tolower(str[i]);			

	cout << str << nln;

	return 0;
}