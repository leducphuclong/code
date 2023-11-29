//Đếm số lượng chữ cái, chữ số trong xâu:
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int dem_chu, dem_so = 0;
	for(int i = 0; i < s.length(); i++) {
		if(isalpha(s[i]))
			dem_chu += 1;
		else if(isdigit(s[i]))
			dem_so += 1;
	}
	cout << dem_chu << " " << dem_so;
	return 0;
}