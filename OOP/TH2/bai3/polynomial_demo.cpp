#include "polynomial.h"

int main() {
    Polynomial poly1({1, 2, 3});  // 1 + 2x + 3x^2
    Polynomial poly2({-1, 0, 1}); // -1 + x^2

    Polynomial sum = poly1 + poly2;
    Polynomial diff = poly1 - poly2;
    Polynomial product = poly1 * poly2;

    std::cout << "Polynomial 1: " << poly1 << std::endl;
    std::cout << "Polynomial 2: " << poly2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << product << std::endl;

    double xValue = 2.0;
    std::cout << "Evaluation at x = " << xValue << ": " << sum.evaluate(xValue) << std::endl;

    return 0;
}
