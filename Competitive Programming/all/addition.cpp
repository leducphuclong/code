#include<iostream>
#include<vector>
#include<string>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	string s1, s2, res;
	getline(cin, s1, nln);
	getline(cin, s2, nln);
	getline(cin, res, nln);
	s1 = ' ' + s1;
	s2 = ' ' + s2;
	res = ' ' + res;
	vector<bool> tic(n+1, 0);
	long rem = 0;
	long i = n;
	while (i >= 1){
		long sum = (s1[i]-'0')+(s2[i]-'0')+rem;
		long add = sum % 10;
		rem = sum / 10;
		if (add == res[i]){
			i--;
			continue;
		}	
		long j = i+1;
		while (j <= n){
			if (((s1[j]-'0')+(s2[j]-'0'))/10+(s1[i]-'0')+(s2[i]-'0') == res[i])
				break;
			++j;
		}
		long op1;
		if (j <= n) 
			op1 = n-j;
		else
			op1 = n-j+1;
		long k = i-1;
		while (k >= 1){
			if (((s1[k]-'0')+(s2[k]-'0'))/10+(s1[i]-'0')+(s2[i]-'0') == res[i])
				break;
			--k;
		}	
		long op2;
		if (k >= 1)
			op2 = i-k;
		else
			op2 = i-k+1;
		if (op1 > op2){
			erase(op1.begin()+i-op1, op1.begin()	i)
		}
	}	
	return 0;
}