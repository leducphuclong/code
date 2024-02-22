#include <iostream>
#include <algorithm> // -> __gcd

using namespace std;

long long reverse(long long n) {
    long long res = 0;
    while (n > 0) {
        res *= 10; //
        res += n % 10;
        n /= 10;
    }
    // res là số đảo ngược của n
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int tc;     cin >> tc;
    while (tc--) {
        long long n;    cin >> n;
        if (__gcd(n, reverse(n)) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
