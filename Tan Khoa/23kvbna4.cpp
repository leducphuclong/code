

#include<iostream>
 
#define nln '\n'
 
using namespace std;
typedef int64_t lo;

 
int pow10[6];
 
bool ascending(int x) {
    int prev = 10;
    while (x > 0) {
        if (x % 10 >= prev)
            return false;
        prev = x % 10;
        x /= 10;
    }
    return true;
}
 
int length(int x) {
    int cnt = 0;
    while (x > 0) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}
 
int inverse(int x) {
    int y = 0;  // inverse number of x
    while (x > 0) {
        y += x % 10 * pow10[length(x)-1];
        x /= 10;
    }
    return y;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // Precompute
    pow10[0] = 1;
    for (int i = 1; i <= 5; ++i)
        pow10[i] = pow10[i-1]*10;
    // Input
    long long n;
    cin >> n;
    // Solve
    lo cnt = 0;
    for (lo x = 1; x <= 1e5; ++x) {
        if (ascending(x) == false)
            continue;
        // x sẽ là số tăng dần
        lo dxc = x*pow10[length(x)]+inverse(x);
        lo dxl = x*pow10[length(x)-1]+inverse(x/10);
        if (dxc <= n)
            ++cnt;
        if (dxl <= n)
            ++cnt;
    }
    cout << cnt << nln;
    return 0;

}

