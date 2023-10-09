#include "vector.h"

int main(int argc, char **argv) {
    vector vt1(5, 1);
    vector vt2(vt1);
    vector vt3 = vt2;
    vector vt4;
    vt4 = vt1;
    cout << vt1 << " " << vt2 << " " << vt3 << " " <<  vt4 << endl;

    return 0;
}