#include <iostream>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int calculate(int a, int b, int (*f)(int, int)) {
    return (*f)(a, b);
}

int main() {
    int (*f)(int, int) = sub;
    cout << sum(2, 3) << ' ' << calculate(2, 3, sum) << endl;
    cout << sub(2, 3) << ' ' << calculate(2, 3, f) << endl;
    return 0;
}
