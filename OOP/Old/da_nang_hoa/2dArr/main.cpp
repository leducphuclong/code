#include "2dArr.h"

int main(int argc, char **argv) {
    Matrix m(2, 3, 1);
    m(0, 2) = 10;
    m.Show();
    return 0;
}