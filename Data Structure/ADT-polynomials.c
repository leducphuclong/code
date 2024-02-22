// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int element_type;

typedef struct operand {
    element_type exponent,  ;
    struct operand *next, *prev;
} *operand_ptr;

typedef struct polynomial {
    operand_ptr header, tail;
} *polynomial_ptr;

// Constant

// Declare global variables.
// End of global variable declaration.

polynomial_ptr initialize(polynomial_ptr p) {

    p = (polynomial_ptr)malloc(sizeof(struct polynomial));

    p->header = (operand_ptr)malloc(sizeof(struct operand));
    p->tail = (operand_ptr)malloc(sizeof(struct operand));

    p->header->prev = p->tail->next = NULL;
    p->header->next = p->tail;
    p->tail->prev = p->header;

    return p;
}

operand_ptr find_position(polynomial_ptr p, element_type exponent) {
    operand_ptr itr = p->header;
    while (itr->next != p->tail) {
        if (itr->next->exponent >= exponent)
            return itr->next;
        itr = itr->next;
    }
    return p->tail;
}

void insert(polynomial_ptr p, element_type coefficient, element_type exponent) {
    operand_ptr pos = find_position(p, exponent);
    if (pos->exponent == exponent) {
        pos->coefficient += coefficient;
        return;
    }
    operand_ptr new_operand = (operand_ptr)malloc(sizeof(struct operand));
    // take the data
    new_operand->exponent = exponent;
    new_operand->coefficient = coefficient;
    // linking
    new_operand->next = pos;
    new_operand->prev = pos->prev;
    pos->prev->next = new_operand;
    pos->prev = new_operand;
}

void discard(polynomial_ptr p, element_type coefficient, element_type exponent) {
    operand_ptr pos = find_position(p, exponent);
    if (pos->exponent != exponent) {
        // If there is no exponent like that
        return;
    }

    // Minus coefficient
    pos->coefficient -= coefficient;
    // If coefficient is equal to zero, we delete it
    if (pos->coefficient == 0) {
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
        free(pos);
    }
}

void print(polynomial_ptr p) {
    operand_ptr itr = p->header->next;
    while (itr->next != p->tail) {
        if (itr->coefficient == 1)
            printf("x^%i + ", itr->exponent);
        else
            printf("%i*x^%i + ", itr->coefficient, itr->exponent);
        itr = itr->next;
    }
    if (itr->coefficient == 1)
        printf("x^%i", itr->exponent);
    else
        printf("%i*x^%i", itr->coefficient, itr->exponent);
}

int main(int argc, char* argv[]) {
    polynomial_ptr p = initialize(p);
    insert(p, 1, 2); // add 1*x^2
    // insert(p, 1, 2); // add 1*x^2
    insert(p, 2, 4); // add 2*x^4
    insert(p, 3, 3); // add 3*x^3
    discard(p, 4, 3); // minus 3*x^3

    print(p);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
