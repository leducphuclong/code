#include<iostream>
#include<conio.h>

#define long long long
#define nln '\n'

using namespace std;

void process(long n)
{
	bool ans = 0;
	for (long c = 0; c <= n; ++c){
		if ((n+c) % 2)
			continue;
		long b = (n+c)/2;
		if (b < 0 || 2*b-c != 24)
			continue;
		long a = 2*c+b-n;
		if (a < 0 || 2*(a-b) != 24)
			continue;
		cout << a << ' ' << b << ' ' << c << nln;
		//cout << 2*(a-b) << ' ' << 2*b-c << ' ' << 2*c-a+b << nln;
		ans = 1;
		break;
	}
	//if (!ans)
	//	cout << "NO" << nln;
}

int main()
{
	/*long n = 24;
	cin >> n;*/
	long n = 1e8;
	for (long i = 1; i <= n; ++i)	
		process(i);
	return 0;
}