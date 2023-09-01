#include<stdio.h>
#include<math.h>

#define long long long
#define nln "%c", '\n'

long sqr(long n)
{
	return n*n;
}

int main()
{
	long n, res[10000], idx = 0;
	scanf("%d", &n);
	while (n > 0){
		res[idx] = (long)sqrt(n);
		++idx;
		n -= sqr(sqrt(n));
	}
	for (long i = 0; i < idx-1; ++i)
		printf("%i^2 + ", res[i], nln);
	printf("%i^2", res[idx-1]);
	return 0;
}