// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//   Every operation except print takes merely O(1) running time.

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int element_type;

typedef struct node {
    element_type element;
    struct node *next, *prev;
} *node_ptr;

typedef struct queue {
    node_ptr header, tail;
} *queue_ptr;

// Constant

// Declare global variables.
// End of global variable declaration.

void Error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

queue_ptr initialize() {
    // Memory Allocation
    queue_ptr q = (queue_ptr)malloc(sizeof(struct queue));
    q->header = (node_ptr)malloc(sizeof(struct node));
    q->tail = (node_ptr)malloc(sizeof(struct node));
    // Linking header and tail
    q->header->prev = q->tail;
    q->header->next = q->tail;
    q->tail->prev = q->header;
    q->tail->next = q->header;
    return q;
}

void print(queue_ptr q) {
    printf("queue now is: ");
    node_ptr itr_node = q->header;
    while (itr_node->next != q->tail) {
        printf("%i ", itr_node->next->element);
        itr_node = itr_node->next;
    }
    printf("\n");
}

bool empty(queue_ptr q) {
    return q->header->next == q->tail;
}

void clear(queue_ptr q) {
    q->header->next = q->tail;
    q->tail->prev = q->header;
}

void push(queue_ptr q, element_type e) {
    printf("e: %i\n", e);
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = e;
    // Linking
    new_node->next = q->tail;
    new_node->prev = q->tail->prev;
    q->tail->prev->next = new_node;
    q->tail->prev = new_node;
}

void pop(queue_ptr q) {
    if (empty(q))
        Error("This queue is now empty, can not pop any more!");
    node_ptr tmp = q->header->next;
    q->header->next = q->header->next->next;
    tmp->next->prev = q->header;
    free(tmp);
}

element_type front(queue_ptr q) {
    if (empty(q))
        Error("This queue is now empty, so there is no front value");
    return q->header->next->element;
}

int main(int argc, char* argv[]) {
    queue_ptr q = initialize();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    pop(q);
    clear(q);
    print(q);
    printf("The front now is: %i\n", front(q));
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
