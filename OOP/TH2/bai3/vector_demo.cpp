#include "vector.h"

int main() {
    // Test default constructor
    Vector v1;

    // Test parameterized constructor
    Vector v2(3);

    // Test copy constructor
    Vector v3(v2);

    // Test assignment operator
    v1 = v3;

    // Test arithmetic operators
    Vector v4 = v2 + v3;
    Vector v5 = v2 - v3;
    Vector v6 = v2 * 2;

    // Test input/output operators
    std::cout << "Enter elements for v1 (size " << v1.size() << "): ";
    std::cin >> v1;

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4 (v2 + v3): " << v4 << std::endl;
    std::cout << "v5 (v2 - v3): " << v5 << std::endl;
    std::cout << "v6 (v2 * 2): " << v6 << std::endl;

    // Test index operator
    try {
        std::cout << "v1[0]: " << v1[0] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
