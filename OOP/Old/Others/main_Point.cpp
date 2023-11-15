#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    Point p1, p2(2, 3), p3(p2);
    p1.Show();
    p2.Show();
    p3.Show();
    p3.TT(1);
    p3.Show();
    return 0;
}