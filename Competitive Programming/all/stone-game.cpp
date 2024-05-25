#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

class Solution {
public:
	map<pair<int, int>, bool> sav;
	// If the turn is True, then that is the Alice turn, else...
	bool play(const vector<int>& piles, int left, int right, 
		int sa, int sb, bool turn) {
		if (sav[make_pair(left, right)] != -1)
			return sav[make_pair(left, right)];
		              
		if (left == right) {
			return sa > sb;
		}

		if (turn)
			return sav[make_pair(left, right)] = 
			(play(piles, left+1, right, sa+piles[left], sb, !turn)
			|| play(piles, left, right-1, sa+piles[right], sb, !turn));
		else
			return sav[make_pair(left, right)] = 
			(play(piles, left+1, right, sa, sb+piles[left], !turn)
			|| play(piles, left, right-1, sa, sb+piles[right], !turn));
	}

	bool stoneGame(vector<int>& piles) {
		int n = piles.size();
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				sav[make_pair(i, j)] = -1;
		return play(piles, 0, n-1, 0, 0, 1);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;	cin >> n;
	vector<int> piles(n);
	for (auto &v : piles)
		cin >> v;

	Solution S;
	cout << S.stoneGame(piles);

	return 0;
}