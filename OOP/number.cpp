#include "number.h"

number::number(double val) : val(val) {}

number::~number() {}

number::operator int() {
    return static_cast<int>(this->val);
}

number::operator double() {
    return static_cast<double>(this->val);
}

ostream& number::operator<<(ostream& out) {
    out << "The value is: " << val << endl;
    return out;
}

