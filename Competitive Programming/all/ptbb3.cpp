#include <iostream>
#include <cmath>

void Solve(float a, float b, float c, float d) {
    constexpr double pi = std::acos(-1.0);
    float delta = b * b - 3 * a * c;
    float k = (9 * a * b * c - 2 * std::pow(b, 3) - 27 * std::pow(a, 2) * d) / (2 * std::sqrt(std::abs(delta) * delta * delta));
    
    if (delta > 0) {
        if (std::abs(k) <= 1) {
            std::cout << "The cubic equation has 3 real roots:" << std::endl;
            std::cout << "x1 = " << (2 * std::sqrt(delta) * std::cos(std::acos(k) / 3) - b) / (3 * a) << std::endl;
            std::cout << "x2 = " << (2 * std::sqrt(delta) * std::cos(std::acos(k) / 3 - (2 * pi) / 3) - b) / (3 * a) << std::endl;
            std::cout << "x3 = " << (2 * std::sqrt(delta) * std::cos(std::acos(k) / 3 + (2 * pi) / 3) - b) / (3 * a) << std::endl;
        } else {
            std::cout << "The cubic equation has 1 real root:" << std::endl;
            std::cout << "x = " << ((std::sqrt(delta) * std::abs(k)) / (3 * a * k)) * (std::cbrt(std::abs(k) + std::sqrt(k * k - 1)) + std::cbrt(std::abs(k) - std::sqrt(k * k - 1))) - b / (3 * a) << std::endl;
        }
    } else if (delta == 0) {
        std::cout << "The cubic equation has 1 real root:" << std::endl;
        std::cout << "x = " << (-b + std::cbrt(std::pow(b, 3) - 27 * std::pow(a, 2) * d)) / (3 * a) << std::endl;
    } else {
        std::cout << "The cubic equation has 1 real root:" << std::endl;
        std::cout << "x = " << ((std::sqrt(std::abs(delta))) / (3 * a)) * (std::cbrt(k + std::sqrt(k * k + 1)) + std::cbrt(k - std::sqrt(k * k + 1))) - (b / (3 * a)) << std::endl;
    }
}

int main() {
    float a, b, c, d;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    std::cout << "d = ";
    std::cin >> d;
    Solve(a, b, c, d);
    return 0;
}