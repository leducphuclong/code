#include <iostream>

using namespace std;

class point
{
private:
    double xval, yval;
public:
    point(double = 1, double = 2);
    ~point();
};

point::point(double x, double y) {
    this->xval = x, this->yval = y;
}

void show() {
    
}

point::~point()
{
}
