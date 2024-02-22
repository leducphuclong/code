#include <iostream>
#include <bitset>
#include <vector>
#include <conio.h>

#define nln '\n'

using namespace std;


void subset(int cur_ss, int k, int n, vector<int> &ss) {
    if (k == 0) {
        ss.push_back(cur_ss);
        return;
    }
    if (n < 0)
        return;
    subset(cur_ss, k, n-1, ss);
    subset(cur_ss ^ (1 << n), k-1, n-1, ss);
}


int main() {
    vector<int> ss;
    subset(0, 3, 5, ss);
    cout << "qtt: " << ss.size() << nln;
    getch();
    for (auto v : ss) {
        cout << bitset<6>(v) << nln;
    }
    return 0;
}