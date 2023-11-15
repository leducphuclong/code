#include <iostream>

using namespace std;

void Chia(int &a, int &b) {
    try {
        if (b == 0)
            throw invalid_argument("b == 0 !!");
        else
            cout << 1.0*a/b << endl;
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
}

int main(int argc, char** argv) {
    int a = 3, b = 2;
    Chia(a, b);
    return 0;
}