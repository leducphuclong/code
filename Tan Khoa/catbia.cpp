#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    long long a,     b;     cin >> a >> b;
    long long x = __gcd(a, b);
    long long sHCN = a*b;
    long long sHV = x*x;
    cout << sHCN/sHV << endl;
    return 0;
}
