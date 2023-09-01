#include<bits/stdc++.h>


#define long long long
#define nln '\n'

using namespace std;

const long M = 100;

int main()
{
	srand(time(0));
	long T = 1;
	//cin >> T;
	while (T--){
		long l = rand() % M;
		long r = rand() % M + l;
		fstream f1;
		f1.open("beauty_number.inp", ios :: out);
		f1 << l << nln << r << nln;
		f1.close();
		system("beauty_number.exe");
		system("beauty_number_brute.exe");
		if (!system("fc beauty_number.out beauty_number.ans")){
			cout << "Test nay sai!" << nln;
			break;
		} 
	}
	return 0;
}