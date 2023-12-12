#include "matrix.h"

Matrix::Matrix() : elements(nullptr), rows(0), cols(0) {}

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    elements = new int*[rows];
    for (size_t i = 0; i < rows; ++i) {
        elements[i] = new int[cols]();
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    elements = new int*[rows];
    for (size_t i = 0; i < rows; ++i) {
        elements[i] = new int[cols];
        for (size_t j = 0; j < cols; ++j) {
            elements[i][j] = other.elements[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < rows; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // Deallocate existing memory
        for (size_t i = 0; i < rows; ++i) {
            delete[] elements[i];
        }
        delete[] elements;

        // Allocate new memory
        rows = other.rows;
        cols = other.cols;
        elements = new int*[rows];
        for (size_t i = 0; i < rows; ++i) {
            elements[i] = new int[cols];
            for (size_t j = 0; j < cols; ++j) {
                elements[i][j] = other.elements[i][j];
            }
        }
    }
    return *this;
}

int& Matrix::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[row][col];
}

const int& Matrix::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[row][col];
}

int Matrix::determinant() const {
    // Placeholder implementation for the determinant calculation
    // Replace this with your actual determinant calculation algorithm
    // For simplicity, assume the matrix is a 2x2 matrix
    if (rows == 2 && cols == 2) {
        return elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0];
    } else {
        throw std::logic_error("Determinant calculation not implemented for non-2x2 matrices");
    }
}

std::istream& operator>>(std::istream& input, Matrix& mat) {
    for (size_t i = 0; i < mat.rows; ++i) {
        for (size_t j = 0; j < mat.cols; ++j) {
            input >> mat.elements[i][j];
        }
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Matrix& mat) {
    for (size_t i = 0; i < mat.rows; ++i) {
        for (size_t j = 0; j < mat.cols; ++j) {
            output << mat.elements[i][j] << ' ';
        }
        output << '\n';
    }
    return output;
}
