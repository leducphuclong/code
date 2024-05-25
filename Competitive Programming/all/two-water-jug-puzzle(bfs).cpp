#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

class Solution {
public:
	int minSteps(int n, int m, int d) {
		queue<tuple<int, int, int>> q;
		q.push(make_tuple(0, 0, 0));
		while (!q.empty()) {
			int cn = get<0>(q.front()), cm = get<1>(q.front()),
			step = get<2>(q.front());
			if (cn == d || cm == d)
				return step;
			q.pop();
			step++;
			if (cn == 0)
				q.push({n, cm, step});
			if (cm == 0)
				q.push({cn, m, step});
			if (cn == n)
				q.push({0, cm, step});
			if (cm == m)
				q.push({cn, 0, step});
			if (cn < n) {
				if (cn + cm <= n) 
					q.push({cn+cm, 0, step});
				else
					q.push({n, cn + cm - n, step});
			}
			if (cm < m) {
				if (cm + cn <= m) 
					q.push({0, cm + cn, step});
				else
					q.push({cm + cn - m, m, step});
			}
		}
		return -1;
	}
};

int main() {
	int n, m, d;	cin >> n >> m >> d;

	Solution S;
	cout << S.minSteps(n, m, d);

	return 0;
}