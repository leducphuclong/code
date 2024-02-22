#include<iostream>
#include<map>
#include<vector>
#include<set>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	long mav = 1e9, stp, t = 0;
	for (long i = 1; i <= mav; ++i){
		t += i;
		if (t > mav){
			stp = i;
			break;
		}
	}
	cout << stp << nln; //44721
	return 0;	
}