#include "Triangle.h"

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
    this->A = A, this->B = B, this->C = C;
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
: A(x1, y1), B(x2, y2), C(x3, y3)  {
}

Triangle:: ~Triangle() {
}

void Triangle::Show() {
    A.Show(), B.Show(), C.Show();
}