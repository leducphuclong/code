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

Point Point::operator-(const Point& q) {
    Point p(this->xVal+q.xVal, this->yVal+q.yVal);
    return p;
}

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1)
}
