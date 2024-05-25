#include<iostream>
#include<fstream>
#include<ctime>

#define long long long
#define nln '\n'

using namespace std;

long random(long miv, long mav)
{
	return miv + rand() % (mav-miv+1);
}

void gen()
{
	fstream fi;
	fi.open("in", ios:: out);
	const int LIM = 5;
	long x = random(2, LIM),
		 y = random(2, LIM),
		 n = random(1, LIM),
		 m = random(1, LIM),
		 k = random(1, LIM);
	fi << x << ' ' << y << ' ' << n << ' ' << m << ' ' << k << nln;
	for (int i = 0; i < n; ++i)
		fi << random(0, x-1) << ' ';
	fi << nln;
	for (int i = 0; i < m; ++i)
		fi << random(0, y-1) << ' ';
	fi.close();
}

void test(bool &stop)
{	
	system("mu_modulo_va_co_so_brute.exe");
	system("mu_modulo_va_co_so3.exe");
	if (system("fc out ans")) {
		cerr << "Test nay sai" << nln;
		stop = 1;
	}
	else {
		cerr << "Test nay dung roi, dang kiem tra tiep" << nln;
	}
}

int main()
{
	srand(time(0));

	cout << "Muon bao nhieu test Long: ";
	long T;
	cin >> T;
	bool stop = 0;
	while (T-- && !stop){
		gen();
		test(stop);
	}
	return 0;
}