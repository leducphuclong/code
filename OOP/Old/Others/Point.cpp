#include "Point.h"
#include <iostream>

using namespace std;

void Point::TT(double d) {
    this->xVal += d, this->yVal += d;
}

void Point::Show() {
    cout << "Coordinate: " << this->xVal << ", " << this->yVal << endl;
}

Point::Point(double x, double y, double z): xVal(x), yVal(y), z(z) {
    Point::n++;
    this->xVal = x, this->yVal = y;
}


Point::~Point() {
    cout << "Delete Point: " << this->xVal << ", " << this->yVal << endl;
}

double Point::Get_xVal() {
    return this->xVal;
}

void Point::Set_xVal(double v) {
    this->xVal = v;
}

void ChangePoint(Point& p) {
    p.xVal = 11111111, p.yVal = 11111111;
}

void Point::Print_Counters() {
    cout << "Counters: " << Point::n << endl;
}
