#include "vector.h"

using namespace std;

int main(int argc, char** argv) {
    vector v1;
    cout << v1 << endl;

    vector v2(3, 3);
    cout << v2 << endl;

    v1 = v2;
    cout << v1 << endl;

    

    return 0;
}