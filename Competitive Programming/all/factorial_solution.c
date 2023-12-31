#include<stdio.h>
#include<string.h>
#include<conio.h>

#define long long long
#define nln printf("%c", '\n');

typedef char bignum[10000];

void inra(bignum N)
{
	printf("%s\n", N);
}

void erase(bignum n, long x, long y) // erase bignum n, from index x, y character
{
	long l = strlen(n);
	for (int i = x+y; i < l; ++i)
		n[i-y] = n[i];
	for (int i = l-y; i < l; ++i)
		n[i] = 0;
}

void del_zero(bignum str)
{
	while (str[0] == '0' && strlen(str) > 1)
		erase(str, 0, 1);
}

void fill0(bignum N, long n)
{
	N = strrev(N);
	long l = strlen(N);
	for (long i = 1; i < n-l+1; ++i)
		N[l-1+i] = '0';
	N = strrev(N);
}

void reverse(char str[])
{
	long idx = strlen(str);
	for (long i = 0; i < idx/2; ++i){
		char tmp = str[i];
		str[i] = str[idx-i-1];
		str[idx-i-1] = tmp;
	}
}

const char* sum(bignum a, bignum b)
{
	if (strlen(a) < strlen(b))
		fill0(a, strlen(b));
	else
		fill0(b, strlen(a));

	char res[10000] = "";
	long rem = 0, idx = 0;
	for (long i = strlen(b)-1; i >= 0; --i){
		long msm = (a[i]-'0')+(b[i]-'0')+rem;
		char c = msm % 10 + '0';
		res[idx++] = c;
		rem = msm / 10;
	}

	if (rem != 0)
		res[idx++] = rem+'0';
	
	reverse(res);

	// convers to return -> I still don't know why have to do this
	char *rt = res;
	return rt;
}

const char* single_multi(bignum a, long b)
{
	char res[10000] = "";
	long rem = 0, idx = 0;
	for (long i = strlen(a)-1; i >= 0; --i){
		long mmt = (a[i]-'0')*b+rem;
		char c = mmt % 10 + '0';
		res[idx++] = c;
		rem = mmt / 10;
	}

	if (rem != 0)
		res[idx++] = rem+'0';

	reverse(res);

	char *rt = res;
	del_zero(rt);
	return rt;
}

const char* multi(bignum a, bignum b)
{
	char res[10000] = "";
	for (long i = strlen(b)-1; i >= 0; --i){
		char smt[10000] = ""; strcpy(smt, single_multi(a, b[i]-'0'));
		long add = strlen(b)-1-i;
		long l = strlen(smt);
		while (add--)
			smt[l] = '0', l += 1;
		char tmp[10000] = ""; strcpy(tmp, sum(res, smt));
		strcpy(res, tmp);
	}

	char *rt = res;
	return rt;
}

long fastpow(long a, long b)
{
	if (b == 0)
		return 1;
	long tmp = fastpow(a, b/2);
	if (b % 2 == 1)
		return tmp*tmp*a;
	else
		return tmp*tmp;
}

long bignum2num(bignum n)
{
	long res = 0;
	for (long i = 0; i < strlen(n); ++i)
		res += (n[i]-'0')*fastpow(10, strlen(n)-i-1);
	return res;
}

const char *num2bignum(long n)
{
	char res[10000] = "";
	long idx = 0;
	while (n > 0){
		char c = n % 10 + '0';
		res[idx++] = c;
		n /= 10;
	}
	
	reverse(res);

	char *rt = res;
	return rt;
}



const char *factorial(long n)
{
	char res[10000] = "1";
	n++;
	while (n--)
		if (n > 0){
			char N[10000] = ""; strcpy(N, num2bignum(n));
			char tmp[10000] = ""; strcpy(tmp, multi(res, N));
			strcpy(res, tmp);
		}

	char *rt = res;
	return rt;
}

int main()
{
	printf("Tinh giai thua cua: ");
	long n;
	scanf("%lli", &n);
	printf("%s", factorial(n));
	return 0;
}