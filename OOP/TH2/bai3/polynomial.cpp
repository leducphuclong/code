#include "polynomial.h"

// Constructors
Polynomial::Polynomial() : coefficients({0.0}) {}

Polynomial::Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {}

// Arithmetic operators
Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t resultDegree = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> resultCoeffs(resultDegree, 0.0);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        resultCoeffs[i] += coefficients[i];
    }

    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        resultCoeffs[i] += other.coefficients[i];
    }

    return Polynomial(resultCoeffs);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t resultDegree = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> resultCoeffs(resultDegree, 0.0);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        resultCoeffs[i] += coefficients[i];
    }

    for (size_t i = 0; i < other.coefficients.size(); ++i) {
        resultCoeffs[i] -= other.coefficients[i];
    }

    return Polynomial(resultCoeffs);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    size_t resultDegree = coefficients.size() + other.coefficients.size() - 1;
    std::vector<double> resultCoeffs(resultDegree, 0.0);

    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return Polynomial(resultCoeffs);
}

// Function to evaluate the polynomial for a given x
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    double xPower = 1.0;

    for (double coef : coefficients) {
        result += coef * xPower;
        xPower *= x;
    }

    return result;
}

// Output operator
std::ostream& operator<<(std::ostream& output, const Polynomial& poly) {
    for (int i = static_cast<int>(poly.coefficients.size()) - 1; i >= 0; --i) {
        if (poly.coefficients[i] != 0.0) {
            output << poly.coefficients[i] << "x^" << i;
            if (i > 0) {
                output << " + ";
            }
        }
    }

    return output;
}
