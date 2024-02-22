#include <iostream>
#include "Point.h"

using namespace std;

void Point::Show() {
    cout << "Coordinate: " << this->xVal << ", " << this->yVal << endl;
}

Point::Point(double x, double y){
    this->xVal = x, this->yVal = y;
}

Point::~Point() {
    cout << "Delete Point: " << this->xVal << ", " << this->yVal << endl;
}