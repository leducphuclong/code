#include<iostream>

typedef long long lo;

bool ascending(int x) { // kiểm số tăng dần
    int prev = 10;
    while (x > 0) {
        if (x % 10 >= prev)
            return false;
        prev = x % 10;
        x /= 10;
    }
    return true;
}

int inverse(int x) { // đảo ngược số
    int y = 0; // inverse number of x
    while (x > 0) {
        y += x % 10 * pow10[length(x)-1];
        x /= 10;
    }
    return y;
}

int length(int x) {  // trả về độ dài của 1 số
    int cnt = 0;
    while (x > 0) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}

int pow10[6];

int main() {
    lo n;
    cin >> n;
    // Precompute
    pow10[0] = 1;
    for (int i = 1; i <= 5; ++i)
        pow10[i] = pow10[i-1]*10;
    lo cnt = 0;
    
    return 0;
}