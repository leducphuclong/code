#include<iostream>
#include<cmath>

#define long long long
#define nln '\n'

using namespace std;

long sqr(long n)
{
	return n*n;
}

int main()
{
	long n;
	cin >> n;
	while (n > 0){
		cout << (long)sqrt(n) << nln;
		n -= sqr(sqrt(n));
	}
	return 0;
}