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
    struct node *next, *prev;
} *node_ptr;

typedef node_ptr list_ptr;

void Error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

list_ptr Initialize(list_ptr l) {
    node_ptr header_node = (node_ptr)malloc(sizeof(struct node));
    // header_node->element = ;
    header_node->next = NULL;
    header_node->prev = NULL;
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
    new_node->prev = l;

    if (l->next != NULL)
        l->next->prev = new_node;
    l->next = new_node;
}

node_ptr Search(list_ptr l, element_type element) {
    node_ptr itr_node = l;
    while (itr_node->next != NULL && itr_node->next->element != element)
        itr_node = itr_node->next;
    return itr_node->next;
}

void delete(list_ptr l, element_type element) {
    node_ptr find_node = Search(l, element);
    if (find_node == NULL)
        return;
    find_node->prev->next = find_node->next;
    if (find_node->next != NULL)
        find_node->next->prev = find_node->prev;
}

void swap_two_adjacent_elements(list_ptr l, element_type left
    , element_type right) {
    node_ptr pos_left = Search(l, left);
    node_ptr pos_right = Search(l, right);
    if (pos_right == NULL || pos_left == NULL)
        Error("Element not found");
    // Linking
    pos_left->prev->next = pos_right;
    if (pos_right->next != NULL)
        pos_right->next->prev = pos_left;
    pos_right->prev = pos_left->prev;
    pos_left->next = pos_right->next;
    pos_right->next = pos_left;
    pos_left->prev = pos_right;
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

    delete(l, 3);

    delete(l, 17);

    print_list(l);

    swap_two_adjacent_elements(l, 2, 26);

    print_list(l);
    printf("OK");

    return 0;
}
