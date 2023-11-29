//Viết ctrinh xóa từ trong xâu:
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	string kq = "";
	for(int i = 0; i < static_cast<int>(s.length()); i++)
		if(isdigit(s[i]) != 0)
			kq += s[i];
	cout << kq;
	// data type of length() is size_t khac int

	return 0;
}