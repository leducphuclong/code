// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

typedef int element_type;

typedef struct operand {
    element_type exponent, coefficient;
    struct operand *next, *prev;
} *operand_ptr;

typedef struct polynomial {
    int id;
    operand_ptr header, tail;
} *polynomial_ptr;

// Constant

// Declare global variables.
// End of global variable declaration.

polynomial_ptr initialize(int id) {
    polynomial_ptr p = (polynomial_ptr)malloc(sizeof(struct polynomial));
    p->id = id;
    p->header = (operand_ptr)malloc(sizeof(struct operand));
    p->tail = (operand_ptr)malloc(sizeof(struct operand));
    p->header->next = p->tail;
    p->header->prev = p->tail;
    p->tail->next = p->header;
    p->tail->prev = p->header;
    return p;
}

operand_ptr create_operand(element_type coefficient, element_type exponent) {
    operand_ptr new_operand = (operand_ptr)malloc(sizeof(struct operand));
    new_operand->coefficient = coefficient;
    new_operand->exponent = exponent;
    return new_operand;
}

operand_ptr find_position(polynomial_ptr p, operand_ptr o) {
    operand_ptr itr = p->header;
    while (itr->next != p->tail) {
        if (itr->next->exponent == o->exponent)
            return itr->next;
        if (itr->next->exponent > o->exponent)
            return itr->next;
        itr = itr->next;
    }
    return NULL;
}

void insert_previous(operand_ptr o1, operand_ptr o2) {
    // insert o2 before o1
    o2->next = o1;
    o2->prev = o1->prev;
    o1->prev->next = o2;
    o1->prev = o2;
}

void insert_operand(polynomial_ptr p, operand_ptr o) {
    operand_ptr found_operand = find_position(p, o);
    if (found_operand == NULL) {
        // there is no operand having the greater or equal with operand 'o'
        insert_previous(p->tail, o);
    } else {
        if (found_operand->exponent == o->exponent) {
            found_operand->coefficient += o->coefficient;
        } else {
            insert_previous(found_operand, o);
        }
    }
}

void merge_polynomials(polynomial_ptr p1, polynomial_ptr p2) {
    operand_ptr itr = p2->header;
    while (itr->next != p2->tail) {
        operand_ptr tmp = create_operand(itr->next->coefficient,
            itr->next->exponent);
        insert_operand(p1, tmp);
        itr = itr->next;
    }
}

polynomial_ptr add(polynomial_ptr p1, polynomial_ptr p2, int id) {
    polynomial_ptr p3 = initialize(id);
    merge_polynomials(p3, p1);
    merge_polynomials(p3, p2);
    return p3;
}

polynomial_ptr single_multiply(polynomial_ptr p, operand_ptr o, int id) {
    polynomial_ptr res_p = initialize(id);
    operand_ptr itr = p->header;
    while (itr->next != p->tail) {
        operand_ptr tmp = create_operand(o->coefficient*itr->next->coefficient,
            o->exponent+itr->next->exponent);
        insert_operand(res_p, tmp);
        itr = itr->next;
    }
    return res_p;
}

polynomial_ptr multiply(polynomial_ptr p1, polynomial_ptr p2, int id) {
    polynomial_ptr p3 = initialize(id);
    operand_ptr itr = p2->header;
    while (itr->next != p2->tail) {
        polynomial_ptr tmp = initialize(id);
        tmp = single_multiply(p1, itr->next, id);
        p3 = add(p3, tmp, id);
        itr = itr->next;
    }
    return p3;
}

void print_polynomial(polynomial_ptr p) {
    printf("Polynomial id %i: ", p->id);
    operand_ptr itr = p->header;
    while (itr->next->next != p->tail) {
        printf("%i*x^%i + ", itr->next->coefficient, itr->next->exponent);
        itr = itr->next;
    }
    printf("%i*x^%i", itr->next->coefficient, itr->next->exponent);
    printf("\n");
}

int main(int argc, char* argv[]) {
    polynomial_ptr p1 = initialize(1);  // 2*x^1 + 3*x^4
    operand_ptr o1 = create_operand(2, 1);
    operand_ptr o2 = create_operand(3, 4);
    insert_operand(p1, o1);
    insert_operand(p1, o2);

    polynomial_ptr p2 = initialize(2);  // 2*x^4 + 4*x^5
    operand_ptr o3 = create_operand(2, 4);
    operand_ptr o4 = create_operand(4, 5);
    insert_operand(p2, o4);
    insert_operand(p2, o3);
    print_polynomial(p1);
    print_polynomial(p2);
    polynomial_ptr p3 = add(p1, p2, 3);
    printf("Sumation is ");
    print_polynomial(p3);
    polynomial_ptr p4 = multiply(p1, p2, 4);
    printf("Multiplication is ");
    print_polynomial(p4);

    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
