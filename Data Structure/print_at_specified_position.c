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

typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef node_ptr list;

// Constant

// Declare global variables.
// End of global variable declaration.

list initialize() {
    list l = (list)malloc(sizeof(struct node));
    l->next = NULL;
    return l;
}

void insert(list l, element_type e) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = e;
    new_node->next = l->next;
    l->next = new_node;
}

void print(list l) {
    node_ptr itr_node = l;
    printf("list now is: ");
    while (itr_node->next != NULL) {
        printf("%i ", itr_node->next->element);
        itr_node = itr_node->next;
    }
    printf("\n");
}

void print_lots(list L, list P) {
    printf("print lost: ");
    node_ptr itr_node = P->next;
    while (itr_node != NULL) {
        int index = itr_node->element;
        node_ptr printed_node = L->next;
        while (--index)
            printed_node = printed_node->next;
        printf("%i ", printed_node->element);
        itr_node = itr_node->next;
    }
}

int main(int argc, char* argv[]) {
    list P = initialize();
    insert(P, 1);
    insert(P, 3);
    insert(P, 4);
    print(P);
    list L = initialize();
    insert(L, 4);
    insert(L, 5);
    insert(L, 6);
    insert(L, 7);
    print(L);
    print_lots(L, P);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
