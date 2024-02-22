#include "vector.h"
#include "matrix.h"

int main() {
    // Test Vector class
    Vector vec1(3);
    std::cout << "Enter elements for Vector (size 3): ";
    std::cin >> vec1;
    std::cout << "Vector 1: " << vec1 << std::endl;

    Vector vec2(3);
    std::cout << "Enter elements for another Vector (size 3): ";
    std::cin >> vec2;
    std::cout << "Vector 2: " << vec2 << std::endl;

    Vector vecSum = vec1 + vec2;
    std::cout << "Vector Sum: " << vecSum << std::endl;

    Vector vecDiff = vec1 - vec2;
    std::cout << "Vector Difference: " << vecDiff << std::endl;

    Vector vecScalar = vec1 * 2;
    std::cout << "Vector Scalar Multiplication: " << vecScalar << std::endl;

    // Test Matrix class
    Matrix mat1(2, 2);
    std::cout << "Enter elements for Matrix (2x2): \n";
    std::cin >> mat1;
    std::cout << "Matrix 1: \n" << mat1 << std::endl;

    int det1 = mat1.determinant();
    std::cout << "Determinant of Matrix 1: " << det1 << std::endl;

    Matrix mat2(2, 2);
    std::cout << "Enter elements for another Matrix (2x2): \n";
    std::cin >> mat2;
    std::cout << "Matrix 2: \n" << mat2 << std::endl;

    int det2 = mat2.determinant();
    std::cout << "Determinant of Matrix 2: " << det2 << std::endl;

    return 0;
}
