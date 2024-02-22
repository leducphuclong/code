#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define nln '\n'

// Global Declaration
vector<int> caps_list[101];
int n, dp[1 << 10][101];
// End global declaration

int main() {
    freopen("in", "r", stdin);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string str; getline(cin, str);
        stringstream s; s << str;
        string tmp;
        while (s >> tmp) {
            stringstream ss; ss << tmp;
        }
        cout << nln;
    }
    return 0;
}