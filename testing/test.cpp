#include <iostream>
#include <bitset>

int main() {
    std::string a, b;
    // std::cout << "Enter binary number a: ";
    std::cin >> a;

    // std::cout << "Enter binary number b: ";
    std::cin >> b;

    // Convert binary strings to decimal
    std::bitset<32> binaryA(a);
    std::bitset<32> binaryB(b);
    unsigned int decimalA = binaryA.to_ulong();
    unsigned int decimalB = binaryB.to_ulong();

    if (decimalB == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
    } else {
        // Perform division
        unsigned int quotient = decimalA / decimalB;

        // Convert quotient to binary string
        std::bitset<32> binaryQuotient(quotient);
        std::string binaryQuotientStr = binaryQuotient.to_string();

        std::cout << "Quotient (in binary): " << binaryQuotientStr << std::endl;
    }

    return 0;
}