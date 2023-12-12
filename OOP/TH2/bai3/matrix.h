#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int** elements;
    size_t rows;
    size_t cols;

public:
    // Constructors and Destructor
    Matrix();
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix& other);
    ~Matrix();

    // Assignment operator
    Matrix& operator=(const Matrix& other);

    // Access operators
    int& operator()(size_t row, size_t col);
    const int& operator()(size_t row, size_t col) const;

    // Determinant calculation
    int determinant() const;

    // Input/output operators
    friend std::istream& operator>>(std::istream& input, Matrix& mat);
    friend std::ostream& operator<<(std::ostream& output, const Matrix& mat);
};
