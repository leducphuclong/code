#include "point.h"

class triangle {
private:
    point pA, pB, pC;
public:
    triangle();
    triangle(const point& pA, const point& pB, const point& pC);
    ~triangle();
    void view();
};
