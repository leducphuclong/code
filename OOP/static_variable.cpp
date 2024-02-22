#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    for (int i = 0; i < 10; ++i) {
        int a = 0;
        static int b = 0; // this is a shared variable
        // which only be initialized once and will exist
        // until program terminated
        a++, b++;
        cout << a << " " << b << endl;
    }
    return 0;
}