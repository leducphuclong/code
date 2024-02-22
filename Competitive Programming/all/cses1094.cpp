#include <iostream>

using namespace std;

typedef int64_t lo;
#define nln '\n'

int main() {
    // Fast I/O
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // Input
    lo n;
    cin >> n;
    lo arr[n];
    for (lo i = 0; i < n; ++i)
        cin >> arr[i];
    // Solve
    lo cnt = 0; // lượng số cần thêm
    for (lo i = 1; i < n; ++i)
        if (arr[i] < arr[i-1])
            cnt += arr[i-1]-arr[i], arr[i] = arr[i-1];
    // Output
    cout << cnt << nln;

    return 0;
}