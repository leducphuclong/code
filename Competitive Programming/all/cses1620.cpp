#include <iostream>
#include <algorithm>

using namespace std;

typedef int64_t lo;
#define nln '\n'

int main() {
    // Fast IO
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // Input
    lo n;
    cin >> n;
    lo arr[n];
    for (lo i = 0; i < n; ++i)
        cin >> arr[i];
    // Solve
    lo miv = arr[0];
    lo res = -99999999;
    lo a, b;
    for (lo i = 1; i < n; ++i) {
        if (arr[i]-miv > res)
            res = arr[i]-miv, a = miv, b = arr[i];
        miv = min(miv, arr[i]);
    }
    // Output
    cout << a << ' ' << b << nln << b-a << nln;
    return 0;
}