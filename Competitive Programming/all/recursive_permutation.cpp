#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

long n, cnt = 0;
int b[100];
bool vst[100];

void rc(long i)
{
	if (i > n){
		++cnt;
		for (long j = 1; j <= n; ++j)
			cout << b[j] << ' ';
		cout << nln;
		return;
	}
	for (long j = 1; j <= n; ++j)
		if (!vst[j]){
			vst[j] = 1;
			b[i]=j;
			rc(i+1);
			vst[j] = 0;
		}
}

int main()
{
	cin >> n;
	rc(1);
	cout << "qtt: " << cnt << nln;
	return 0;
}