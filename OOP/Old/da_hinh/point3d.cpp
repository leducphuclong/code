#include "point3d.h"

point3d::point3d(int x, int y, int z): zVal(z) {
    point tmp(x, y);    this->xVal = tmp.xVal; this->yVal = tmp.yVal;
}

point3d::~point3d() {
}

void point3d::show() {
    point::show();
}

void point3d::show3d() {
    point::show();
    cout << " | " << "z value: " << zVal;
}

