#include <iostream>

using namespace std;

int main() {
    int n;  cin >> n;
    long long arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    long long prev_min = arr[0]; // Biến này để lưu giá trị nhỏ nhất trước đó

    long long ans = 0; // Biến này để lưu kết quả

    int pos_min = -1, pos_max = -1, pos_prev_min = 0;
    // pos_min để lưu giá trị phần tử nhỏ hơn
    // pos_max để lưu giá trị phần tử lớn hơn
    // pos_prev_min để lưu chỉ số của phần tử nhỏ nhất trước đó

    for (int i = 1; i < n; ++i) {
        if (arr[i] - prev_min > ans) {
            ans = arr[i] - prev_min; // lưu lại kết quả
            pos_max = i; // lưu lại chỉ số của phần tử lớn
            pos_min = pos_prev_min; // lưu lại chỉ số của phần tử nhỏ
        }
       if (arr[i] < prev_min) {
            prev_min = arr[i]; // Lưu giá trị nhỏ nhất trước đó
            pos_prev_min = i; // lưu chỉ số của giá trị nhỏ nhất trước đó
       }
    }
    cout << pos_min+1 << ' ' << pos_max+1 << endl;
    cout << ans << endl;

    return 0;
}
