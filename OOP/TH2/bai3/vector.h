#include <iostream>

class Vector {
private:
    int* elements;
    size_t dim;

public:
    // Constructors and Destructor
    Vector();
    Vector(size_t size);
    Vector(const Vector& other);
    ~Vector();

    // Assignment operator
    Vector& operator=(const Vector& other);

    // Arithmetic operators
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(int scalar) const;

    // Input/output operators
    friend std::istream& operator>>(std::istream& input, Vector& vec);
    friend std::ostream& operator<<(std::ostream& output, const Vector& vec);

    // Index operator
    int& operator[](size_t index);

    // Size operator
    size_t size() const;
};
