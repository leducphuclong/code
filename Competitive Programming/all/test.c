#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int degree;
    int *coefficients;
} Polynomial;

void initPolynomial(Polynomial *poly, int degree) {
    poly->degree = degree;
    poly->coefficients = (int*) malloc((degree+1) * sizeof(int));
    for (int i = 0; i <= degree; i++) {
        poly->coefficients[i] = 0;
    }
}

void setCoefficient(Polynomial *poly, int degree, int coefficient) {
    poly->coefficients[degree] = coefficient;
}

Polynomial addPolynomials(Polynomial poly1, Polynomial poly2) {
    int degree = (poly1.degree > poly2.degree) ? poly1.degree : poly2.degree;
    Polynomial result;
    initPolynomial(&result, degree);
    for (int i = 0; i <= degree; i++) {
        result.coefficients[i] = poly1.coefficients[i] + poly2.coefficients[i];
    }
    return result;
}

Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
    int degree = poly1.degree + poly2.degree;
    Polynomial result;
    initPolynomial(&result, degree);
    for (int i = 0; i <= poly1.degree; i++) {
        for (int j = 0; j <= poly2.degree; j++) {
            result.coefficients[i+j] += poly1.coefficients[i] * poly2.coefficients[j];
        }
    }
    return result;
}

void printPolynomial(Polynomial poly) {
    printf("%dx^%d", poly.coefficients[0], poly.degree);
    for (int i = 1; i <= poly.degree; i++) {
        printf(" + %dx^%d", poly.coefficients[i], poly.degree-i);
    }
    printf("\n");
}

int main() {
    Polynomial poly1, poly2, poly3, poly4;
    initPolynomial(&poly1, 3);
    initPolynomial(&poly2, 2);
    setCoefficient(&poly1, 3, 2);
    setCoefficient(&poly1, 2, 5);
    setCoefficient(&poly1, 1, 1);
    setCoefficient(&poly1, 0, 3);
    setCoefficient(&poly2, 2, 4);
    setCoefficient(&poly2, 1, 2);
    setCoefficient(&poly2, 0, 1);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    poly3 = addPolynomials(poly1, poly2);
    printf("Addition result: ");
    printPolynomial(poly3);

    poly4 = multiplyPolynomials(poly1, poly2);
    printf("Multiplication result: ");
    printPolynomial(poly4);

    free(poly1.coefficients);
    free(poly2.coefficients);
    free(poly3.coefficients);
    free(poly4.coefficients);

    return 0;
}
