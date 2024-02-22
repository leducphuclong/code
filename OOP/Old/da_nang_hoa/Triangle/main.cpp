#include <iostream>
#include "Triangle.h"

using namespace std;

// int Point::n = 0;

int main(int argc, char **argv) {
    Point pa;
    Point pb(11, 11), pc(12, 12);
    Triangle t1(pa, pb, pc);
    Triangle t2;
    t1.Show();
    t2.Show();
    return 0;
}