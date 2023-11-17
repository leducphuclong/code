#include "complex.h"
#include <iostream>
#include <iomanip>

using namespace std;

complex::complex(double real, double imag) {
    setComplexNumber(real, imag);
}

complex::~complex() {
}

void complex::add_real(const complex& tmp) {
    this->realPart += tmp.realPart;
}

void complex::add_image(const complex &tmp) {
    this->imagPart += tmp.imagPart;
}

complex operator+(const complex& a, const complex& b) {
    complex c;
    c.add_image(a), c.add_image(b);
    c.add_real(a), c.add_real(b);
    return c;
}

void complex::sub_image(const complex& tmp) {
    this->imagPart -= tmp.imagPart;
}

void complex::sub_real(const complex& tmp) {
    this->realPart -= tmp.realPart;
}

complex operator-(const complex& a, const complex& b) {
    complex c;
    c.add_image(a), c.sub_image(b);
    c.add_real(a), c.sub_real(b);
    return c;
}

ostream& operator<<(ostream& os, const complex& tmp) {
   os << setprecision(2) << fixed << tmp.realPart << " + " << tmp.imagPart << 'i';
   return os;
}
