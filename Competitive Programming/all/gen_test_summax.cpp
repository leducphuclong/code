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
	fi.open("summax.inp", ios:: out);
	long n = random(1, 10);
	fi << n << nln;
	for (long i = 0; i < n; ++i){
		for (long j = 0; j < n; ++j)
			fi << random(1, n) << ' ';
		fi << nln;
	}
	fi.close();
}

void test(bool &stop)
{
	system("summax.exe");
	system("summax2.exe");
	if (system("fc summax.out summax.ans.out"))
		stop = 1;
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