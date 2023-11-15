#include "Number.h"

int main(int argc, char **argv) {
    Number n;
    // cout << n.value << endl;
    double y = double(n);

    // int x = int(n);
    // cout << "x: " << x << endl;
    // cout << "y: " << y << endl;

    // cout << "n: " << n << endl;

    Number n1(2), n2(3), n4;
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
    n1 = ++(++n2);
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
    cout << "n4: " << n4 << endl;
    n2 = (n4++)++;
    // cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;
    cout << "n4: " << n4 << endl;
    return 0;
}
