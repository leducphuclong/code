//Convert_binaryStr_Decimal: chuyển số nhị phân sang thập phân: KTLT Nhom 15: ERROR
#include <bits/stdc++.h>

using namespace std;

long long thap_phan(string &n) {
	long long s = 0, pow2 = 1; // pow(2, 0) = 1 (2 ^ 0 = 1)
	for(int i = n.length() - 1; i >= 0; i--) {
		if(n[i] == '1') {
			s += pow2;
		}
		pow2 *= 2ll;
	}
	return s;
}

int main() {
	string n; cin >> n;
	cout << thap_phan(n);
	return 0;
}