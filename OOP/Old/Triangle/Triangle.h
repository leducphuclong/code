#include "Point.h"

class Triangle {
private:
    Point A, B, C;
public:
    Triangle(const Point&, const Point&, const Point&);
    Triangle(double = 1, double = 1, double = 2, double = 2, double = 3, double = 3);
    ~Triangle();
    void Show();
};
