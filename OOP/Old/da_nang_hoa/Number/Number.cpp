#include "Number.h"

Number::Number(double value) {
    this->value = value;
}

Number::~Number() {
}

Number::operator int() {
    return (int)(this->value);
}

Number::operator double() {
    return this->value;
}

ostream& operator<<(ostream& out,  const Number& n) {
    out << n.value;
    return out;
}

Number& Number::operator++() {  // Prefix
    this->value++;
    return *this;
}


// const Number Number::operator++(int) { // Postfix
//     Number tmp(*this);
//     this->value++;
//     return tmp;
// }

const Number Number::operator++(int) { // Double Postfix
    Number tmp(*this); // Create a copy of the current object
    this->value += 2;  // Increment the value of the current object by 2
    return tmp;        // Return the copy (the value before increment)
}

const Number Number::operator++(int) { // Double Postfix
    Number tmp(*this); // Create a copy of the current object
    this->value += 2;  // Increment the value of the current object by 2
    return tmp;        // Return the copy (the value before increment)
}