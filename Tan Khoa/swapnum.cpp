#include <iostream>
#include <algorithm>

using namespace std;

bool find_zero(string n) { // tìm số 0
    // trả về true nếu như n có số 0
    // trả về false nếu như n không có số 0
    for (char c : n)
        if (c == '0')
            return true;
    // Sau khi chạy xong vòng lặp trên
    // Nếu chương trình chạy được xuống đây
    // tức là nó chưa từng return true
    // đồng nghĩa việc nó chưa từng gặp số 0
    // Vậy ta return false, bởi vì 'n' không có
    // số 0
    return false;
}

bool check_3(string n) {
    // Hàm trả về true nếu n chia hết cho 3
    // Hàm trả về false nếu n không chia hết cho 3
    int t = 0; // lưu tổng các chữ số của n
    for (auto c : n)
        t += c - '0';

    if (t % 3 == 0)
        return true;
    else
        return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    string n;       cin >> n;
    if (find_zero(n) == true && check_3(n) == true) {
        sort(n.rbegin(), n.rend());
        // sắp xếp các chữ số giảm dần
        // thì số 0 sẽ tự động xuống dưới vị trí
        // cuối cùng để số n chia hết cho 10
        cout << n << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
