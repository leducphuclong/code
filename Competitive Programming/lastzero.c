#include<stdio.h>
#include<math.h>

#define long long long
#define nln '\n'

int main()
{
	double x = 2, y = 8;
	printf("%lf", log(y)/log(x));
	return 0;
	long n;
	scanf("%lli", &n);
	long fiv = 1, res = 0;
	while (fiv <= n){
		fiv *= 5;
		res += n / fiv;
	}
	printf("%lli\n", res);
	return 0;
}