#pragma once

#include <iostream>
#include <vector>

class Polynomial {
private:
    std::vector<double> coefficients;

public:
    // Constructors
    Polynomial();
    Polynomial(const std::vector<double>& coeffs);

    // Arithmetic operators
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    // Function to evaluate the polynomial for a given x
    double evaluate(double x) const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& output, const Polynomial& poly);
};
