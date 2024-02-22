#include <iostream>

using namespace std;

int tong_chu_so(string n) {
    int tong = 0;
    while (n.empty() == false) { // thực hiện khi xâu chưa rỗng
        tong += n.back() - '0'; // chuyển về số rồi cộng vào tổng
        n.pop_back(); // vứt kí tự cuối cùng
    }
    return tong;
}

int main() {
    string n;       cin >> n;
    cout << tong_chu_so(n) << endl;
    return 0;
}
