#include "point4d.h"

point4d::point4d(int x, int y, int z, int t) : point3d(x, y, z), tVal(t) {
    cout << "construct point 4d" << endl;
}

point4d::~point4d() {
    cout << "destruct point 4d" << endl;
}

void point4d::show4d() {
    point::show();
    cout << " | " << "z value: " << this->zVal << " | " << "t value: " << this->tVal << endl;
}

void point4d::show() {
    point3d::show3d();
    cout << " | " << "t value: " << this->tVal;
}
