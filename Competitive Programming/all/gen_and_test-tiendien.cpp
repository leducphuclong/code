#include<iostream>
#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<ctime>

#define long long long
#define nln '\n'

const long N = 200;

using namespace std;

void generate()
{
	fstream fi;
	fi.open("tiendien.inp", ios:: out);
	long bse = rand() % N;
	fi << bse << nln << bse + rand() % N << nln;
	fi.close();
}

bool test()
{

	system("tiendien.exe");
	system("tiendien2.exe");
	fstream fo1, fo2;
	fo1.open("tiendien.out", ios:: in);
	fo2.open("tiendien.ans", ios:: in);
	string s1, s2;
	getline(fo1, s1, nln);
	getline(fo2, s2, nln);
	fo1.close();
	fo2.close();
	return s1 == s2;
}

int main()
{
	srand(time(0));
	long T;
	cout << "How many test Long? ";
	cin >> T;
	while (T--){
		generate();
		if (test())
			cout << "This test is OK, Long.";
		else{
			cout << "This test has some problems, Long.";
			break;
		}
		cout << nln;
	}
	return 0;
}