#include "complex.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    complex n1(2, 3), n2(-10, 2), n3 = n1-n2;
    cout << n3 << endl;

    return 0;
}