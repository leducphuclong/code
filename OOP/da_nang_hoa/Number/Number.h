#include <iostream>
using namespace std;

class Number {
    private:
    public: 
        double value;
        Number(double = 3.141592653589793);
        ~Number();
        operator int();
        operator double();
        friend ostream& operator<<(ostream&, const Number&);
        Number& operator++();  // Prefix
        const Number operator++(int); // Postfix
};