#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // 3
    // 5 6 7
    //freopen("test.inp", "r", stdin);
    int n; cin >> n; int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    const int N = int(1e6) + 5;
    int cnt[N];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i)
        cnt[arr[i]] += 1;

    cout << "arr: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;

    for (int i = 1; i < 20; ++i)
        cout << i << " : " << cnt[i] << endl;

    return 0;
}
