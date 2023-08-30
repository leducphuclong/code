#include<iostream>

#define nln '\n'

using namespace std;

const int add = 0;

int res[100];
bool col[100], di1[200], di2[200];
int n, cnt = 0;

void play_game(int r);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	play_game(1);
	cout << "quantity: " << cnt;
	return 0;
}

void play_game(int r)
{
	if (r > n){
		for (int i = 1; i <= n; ++i)
			cout << res[i] << ' ';
		cout << nln;
		++cnt;
		return;
	}	
	for (int c = 1; c <= n; ++c){
		if (!col[c] && !di1[r-c+add] && !di2[r+c-add]){
			col[c] = 1;
			di1[r-c+add] = 1;
			di2[r+c-add] = 1;
			res[r] = c;
			play_game(r+1);
			col[c] = 0;
			di1[r-c+add] = 0;
			di2[r+c-add] = 0;
		}
	}
}