#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

class Solution {
public:
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a%b);
	}

	int pour(int n, int m, int d) { // d <= max(n, m)
		int step = 0, cn = 0, cm = 0;
		while (cn != d && cm != d) {
			if (cn == 0) {
				cn = n;
			} else if (cm == m) {
				cm = 0;
			} else {
				if (cm + cn >= m) {
					cn = cm+cn - m;
					cm = m;
				} else {
					cm += cn;
					cn = 0;
				}
			}
			step++;
		}
		return step;
	}

	int minSteps(int n, int m, int d) {
		if (d > max(n, m) || d % gcd(n, m) != 0)
			return -1;
		return min(pour(n, m, d), pour(m, n, d));
	}
};

void test() {
}

int main() {
	int n, m, d;	cin >> n >> m >> d;

	Solution S;
	cout << S.minSteps(n, m, d);

	return 0;
}