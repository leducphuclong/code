#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Input
    int n;  cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    // Solve
    int g = 0; // UCLN của
    for (int i = 0; i < n; ++i)
        g = __gcd(g, arr[i]);
    int ans = -1; // ước nhỏ nhất của g
    for (int i = 2; i <= g; ++i)
        if (g % i == 0) {
            ans = i;
            break;
        }
    cout << ans << endl;
    return 0;
}
