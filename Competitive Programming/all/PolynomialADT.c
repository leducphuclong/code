// Copyright (c) 2023, Le Duc Phuc Long

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define nln '\n'

// Declare global variables.

typedef struct polynomial {
    int degree;
    int *coefficients;
} Polynomial;

void Init(Polynomial *poly, int degree) {
    poly->degree = degree;
    poly->coefficients = (int*)(malloc((degree+1)*sizeof(int)));
    for (int i = 0; i <= degree; ++i)
        poly->coefficients[i] = 0;
}

void set_coefficient(Polynomial *poly, int degree, int coefficient) {
    poly->coefficients[degree] = coefficient;
}

Polynomial add_two_polynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial poly;
    Init(&poly, (poly1->degree > poly2->degree) ? poly1->degree : poly2->degree);

    if (poly1->degree > poly2->degree) {
        Polynomial* temp = poly1;
        poly1 = poly2;
        poly2 = temp;
    }

    for (int i = 0; i <= poly1->degree; ++i)
        poly.coefficients[i] = poly1->coefficients[i] + poly2->coefficients[i];
    for (int i = poly1->degree+1; i <= poly2->degree; ++i)
        poly.coefficients[i] = poly2->coefficients[i];

    return poly;
}

Polynomial multiply_two_polynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial poly;
    Init(&poly, poly1->degree+poly2->degree);
    for (int e2 = 0; e2 <= poly2->degree; ++e2) {
        Polynomial temp;
        Init(&temp, poly1->degree+poly2->degree);
        for (int e1 = 0; e1 <= poly1->degree; ++e1)
            temp.coefficients[e1+e2] = poly1->coefficients[e1]*poly2->coefficients[e2];
        poly = add_two_polynomials(&poly, &temp);
    }
    return poly;
}

void print_polynomial(Polynomial *poly) {
    for (int i = poly->degree; i >= 0; --i)
        printf("%i*x^%i ", poly->coefficients[i], i);
    printf("\n");
}

int main(int argc, char* argv[]) {
    Polynomial poly1, poly2;

    Init(&poly1, 2);
    set_coefficient(&poly1, 2, 2);
    set_coefficient(&poly1, 0, 3);
    printf("Polynomial 1: ");
    print_polynomial(&poly1);

    Init(&poly2, 1);
    set_coefficient(&poly2, 1, 1);
    set_coefficient(&poly2, 0, 4);
    printf("Polynomial 2: ");
    print_polynomial(&poly2);


    Polynomial poly3 = add_two_polynomials(&poly1, &poly2);
    printf("Summation: ");
    print_polynomial(&poly3);

    Polynomial poly4 = multiply_two_polynomials(&poly1, &poly2);
    printf("Multiplication: ");
    print_polynomial(&poly4);

    return 0;
}
