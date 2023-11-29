#include <iostream>
#include <vector>

using namespace std;

int main() {
    //int n, m;   cin >> n >> m;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for (auto v : a)
        cout << v << ' ';
    cout << endl;

    for (auto &v : a)
        v += 2;

    for (auto v : a)
        cout << v << ' ';
    cout << endl;

    return 0;
}
