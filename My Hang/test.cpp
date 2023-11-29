#include <iostream>

using namespace std;

long long getNum(string str) {
	// str = "xe 100 pk" -> 100
	long long num = 0;
	for (auto v : str)
		if (isdigit(v))
			num = num*10+(v-'0'); // v-'0' to convert v from char to integer
	return num;
}

int main() {
	cout << getNum(" 3412 1231 sdfsaf") << endl;
	return 0;
}