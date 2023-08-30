// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int element_type;

typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef node_ptr list, position;

// Constant

// Declare global variables.
// End of global variable declaration.

void Error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

list create() {
    list l = (list)malloc(sizeof(struct node));
    l->next = NULL;
    return l;
}

bool empty(list l) {
    return l->next == NULL;
}

bool is_last(position p) {
    return p->next == NULL;
}

position find_prev(element_type element, list l) {
    position p = l;
    while (p->next != NULL && p->next->element != element)
        p = p->next;
    return p;
}

position find_pos(element_type element, list l) {
    return find_prev(element, l)->next;
}

void delele(element_type element, list l) {
    position prev_p = find_prev(element, l);
    if (prev_p == NULL)
        return;
    position pos_p = prev_p->next;
    prev_p->next = prev_p->next->next;
    free(pos_p);
}

void insert(element_type element, list l, position p) {
    // This routine inserts an element to the list l after node p
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    if (new_node == NULL)
        Error("Memory Allocation Error");
    new_node->element = element;
    new_node->next = p->next;
    p->next = new_node;
}

void clear(list l) {
    node_ptr itr_node = l->next;
    while (itr_node != NULL) {
        node_ptr tmp_node = itr_node;
        itr_node = itr_node->next;
        free(tmp_node);
    }
    l->next = NULL;
}

void print(list l) {
    node_ptr itr_node = l;
    printf("Print list: ");
    while (itr_node->next != NULL) {
        printf("%i ", itr_node->next->element);
        itr_node = itr_node->next;
    }
    printf("\n");
}

void swap_two_adjacent_elements(list l, element_type left, element_type right) {
    // This function is book's exercise
    // Assume left and righ are two adjacent elements
    node_ptr pos_right = find_pos(right, l);
    node_ptr pos_left = find_pos(left, l);
    if (pos_right == NULL || pos_left == NULL)
        Error("This node does not exist!");
    node_ptr prev_left = find_prev(left, l);
    node_ptr next_right = find_pos(right, l)->next;
    // Linking
    prev_left->next = pos_right;
    pos_right->next = pos_left;
    pos_left->next = next_right;
}

int main(int argc, char* argv[]) {
    list l = create();
    insert(10, l, l);
    insert(11, l, l);
    insert(12, l, find_pos(10, l));
    insert(14, l, l);
    // clear(l);
    print(l);
    swap_two_adjacent_elements(l, 14, 11);
    print(l);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
