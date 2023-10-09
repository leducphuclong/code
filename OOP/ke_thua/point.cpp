#include "point.h"

point::point(int x, int y) : xVal(x), yVal(y) {
}

point::~point() {
}

void point::show() {
    cout << "x value: " << xVal << " | " << "y value: " << yVal;
}