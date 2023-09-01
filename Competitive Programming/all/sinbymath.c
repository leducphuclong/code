#include<stdio.h>
#include<math.h>
#include<conio.h>

#define long long long
#define nln '\n'

const double EPS = 1e-6;
const long MXF = 103;

long fac[103];

double fastpow(double m, long n, long c)
{
	if (n == 0)
		return (double)1/c;
	return fastpow(m, n-1, c)*m;
}

int main()
{
	// khoi tao mang giai thua
	long idx = 0;
	fac[idx] = 1;
	while (idx++ < MXF)
		fac[idx] = fac[idx-1]*idx;

	double x;
	scanf("%lf", &x);

	long n = 0;
	double res = 0;
	while (fabs(fastpow(x, 2*n+1, fac[2*n+1])) >= EPS){
		res += fastpow(-1, n, 1)*fastpow(x, 2*n+1, fac[2*n+1]);
		n++;
	}
	printf("%f\n", res);
	printf("%.6f\n", sin(x));
	return 0;
}

