#include "vector.h"

// Constructors
Vector::Vector() : elements(nullptr), dim(0) {}

Vector::Vector(size_t size) : dim(size) {
    elements = new int[dim];
    // Initialize elements here if needed
}

Vector::Vector(const Vector& other) : dim(other.dim) {
    elements = new int[dim];
    for (size_t i = 0; i < dim; ++i) {
        elements[i] = other.elements[i];
    }
}

// Destructor
Vector::~Vector() {
    delete[] elements;
}

// Assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        dim = other.dim;
        elements = new int[dim];
        for (size_t i = 0; i < dim; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

// Arithmetic operators
Vector Vector::operator+(const Vector& other) const {
    Vector result(dim);
    for (size_t i = 0; i < dim; ++i) {
        result.elements[i] = elements[i] + other.elements[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& other) const {
    Vector result(dim);
    for (size_t i = 0; i < dim; ++i) {
        result.elements[i] = elements[i] - other.elements[i];
    }
    return result;
}

Vector Vector::operator*(int scalar) const {
    Vector result(dim);
    for (size_t i = 0; i < dim; ++i) {
        result.elements[i] = elements[i] * scalar;
    }
    return result;
}

// Input/output operators
std::istream& operator>>(std::istream& input, Vector& vec) {
    for (size_t i = 0; i < vec.dim; ++i) {
        input >> vec.elements[i];
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Vector& vec) {
    for (size_t i = 0; i < vec.dim; ++i) {
        output << vec.elements[i] << ' ';
    }
    return output;
}

// Index operator
int& Vector::operator[](size_t index) {
    if (index < dim) {
        return elements[index];
    } else {
        // Handle out-of-bounds access, e.g., throw an exception
        throw std::out_of_range("Index out of bounds");
    }
}

// Size operator
size_t Vector::size() const {
    return dim;
}
