#include "point.h"

point::point(int xVal, int yVal) : xVal(xVal), yVal(yVal) {

}

point::~point() {

}

istream& operator>>(istream& in, point& p) {
    cout << "Enter x Value: ";  in >> p.xVal;
    cout << "Enter y Value: ";  in >> p.yVal;
    return in;
}

ostream& operator<<(ostream& out, const point& p) {
    out << "In this point: " << endl;
    out << "x Value is: " << p.xVal << endl;
    out << "y Value is: " << p.yVal << endl;
    return out;
}
