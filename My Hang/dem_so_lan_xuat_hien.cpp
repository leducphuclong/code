//Viết hàm đếm 1 ký tự xuất hiện bao nhiêu lần trong xâu:
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int dem_kytu(string &s, char kt) {
	int dem = 0;
	for(char c : s)
		if(c == kt)
			dem += 1;
	return dem;
}

int main() {

	char kt;
	cin >> kt; // a

	cin.ignore(); // clear buffer

	string s;
	getline(cin, s);
	
	cout << count(s.begin(), s.end(), kt) << endl;
	return 0; 
}