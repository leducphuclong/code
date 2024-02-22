#include <iostream>
#include "triangle.h"

using namespace std;

triangle::triangle(): pA(0, 0), pB(0, 0), pC(0, 0) {
}

triangle::triangle(const point& pA, const point& pB, const point& pC)
: pA(pA), pB(pB), pC(pC) {
}

triangle::~triangle() {
}

void triangle::view() {
    cout << "These are coordinates of three points of the triangle: " << endl;;
    cout << "pA: " << pA.get_xV() << ' ' << pA.get_yV() << endl;
    cout << "pB: " << pB.get_xV() << ' ' << pB.get_yV() << endl;
    cout << "pC: " << pC.get_xV() << ' ' << pC.get_yV() << endl;
    cout << endl;
}