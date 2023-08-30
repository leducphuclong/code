// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define nln '\n'

// Declare global variables.

typedef int element_type;

typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef node_ptr list_ptr;

list_ptr Initialize(list_ptr l) {
    node_ptr header_node = (node_ptr)malloc(sizeof(struct node));
    // header_node->element = ;
    header_node->next = NULL;
    return header_node;
}

void print_list(list_ptr l) {
    node_ptr itr_node = l;
    while (itr_node->next != NULL) {
        printf("%i ", itr_node->next->element);
        itr_node = itr_node->next;
    }
    printf("\n");
}

void Insert(list_ptr l, element_type element) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = element;
    new_node->next = l->next;
    l->next = new_node;
}

node_ptr Search(list_ptr l, element_type element) {
    node_ptr itr_node = l;
    while (itr_node->next != NULL && itr_node->next->element != element)
        itr_node = itr_node->next;
    return itr_node;
}

void delete(list_ptr l, element_type element) {
    node_ptr find_node = Search(l, element);
    if (find_node == NULL)
        return;
    find_node->next = find_node->next->next;
}

int main(int argc, char* argv[]) {
    list_ptr l;

    l = Initialize(l);

    Insert(l, 27);
    Insert(l, 26);
    Insert(l, 2);
    Insert(l, 17);

    print_list(l);

    delete(l, 27);

    print_list(l);

    return 0;
}
