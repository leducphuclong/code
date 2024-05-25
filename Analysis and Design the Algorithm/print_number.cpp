// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

void printDigit(const char digit) {
    cout << digit;
}

void printIntegerPart(const int number) {
    if (number < 10) {
        cout << number;
        return;
    }
    printIntegerPart(number/10);
    cout << number % 10;
}

void printFractionalPart(const double number) {
    const double eps = 1e-10;
    if (abs((int)(number) - number) <= eps) {
        return;
    }
    cout << int(number*10);
    printFractionalPart(number*10 - int(number*10)); 
}

void printNumber(const double number) {
    int sign = 1;
    if (number < 0) {
        cout << '-';
        sign = -1;
    }

    int intPart = number*sign;
    double FractionalPart = number - intPart*sign; FractionalPart *= sign;

    printIntegerPart(intPart);
    cout << '.';
    printFractionalPart(FractionalPart);
}

int main(int argc, char** argv) {
    double n = -123.456;

    printNumber(n);

    return 0;
}