#include "matrix.h"

using namespace std;

int main(int argc, char** argv) {
    matrix m1, m2(1, 2, 3);

    cout << m1 << m2 << endl;

    m2(0, 1) = 5;

    cout << m2 << endl;
    
    cout << "DONE" << endl;

    return 0;
}