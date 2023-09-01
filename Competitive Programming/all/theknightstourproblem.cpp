#include<iostream>
#include<vector>

#define nln '\n'

using namespace std;

int brd[100][100];
vector<pair<long, long>> mve{{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}};

void init()
{
	auto tmp = mve;
	for (auto i : tmp)
	 	mve.push_back(i.second, i.first);
}

void go(long x, long y)
{

}

int main()
{
	long n;
	cin >> n;
	init();
	go(0, 0);
	return 0;
}