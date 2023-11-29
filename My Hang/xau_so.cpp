#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		long long res = 0;
		string digits = "";
		bool minus = false; // kiểm tra xem có dấu trừ không
		s += 'z';
		for (auto c : s) {
			if (c == '-')
				minus = true;
			if (isdigit(c)) {
				digits += c;
			} else { // nếu c không phải 
				if (digits == "")
					continue;
				if (minus == true)
					res -= stoi(digits), minus = false; // để tính số khác;
				else
					res += stoi(digits);
				digits = "";
			}
		}
		cout << res << endl;
	}
	return 0;
}