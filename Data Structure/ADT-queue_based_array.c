// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

//  Every operation except print takes merely O(1) running time.

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int element_type;

typedef struct queue {
    unsigned int max_size, current_size, front_index, back_index;
    element_type *array;
} *queue_ptr;

// Constant

// Declare global variables.
// End of global variable declaration.

void Error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

queue_ptr initialize(int max_size) {
    queue_ptr q = (queue_ptr)malloc(sizeof(struct queue));
    q->max_size = max_size;
    q->current_size = 0;
    q->front_index = 1;
    q->back_index = 0;
    q->array = (element_type*)malloc(sizeof(element_type)*max_size);
}

void make_null(queue_ptr q) {
    q->current_size = 0;
    q->front_index = 1;
    q->back_index = 0;
}

bool is_full(queue_ptr q) {
    return q->current_size == q->max_size;
}

bool is_empty(queue_ptr q) {
    return q->current_size == 0;
}

void find_push_position(queue_ptr q) {
    if (++q->back_index == q->max_size)
        q->back_index = 0;
}

void push(queue_ptr q, element_type e) {
    if (is_full(q))
        Error("queue is full now, can not push anymore !");

    find_push_position(q);  // Increase the back index
    q->array[q->back_index] = e;
    q->current_size++;
}

void find_pop_position(queue_ptr q) {
    if (++q->front_index == q->max_size)
        q->front_index = 0;
}

void pop(queue_ptr q) {
    if (is_empty(q))
        Error("queue is empty now, can not pop anymore");

    find_pop_position(q);
    q->current_size--;
}

element_type front_value(queue_ptr q) {
    return q->array[q->front_index];
}

element_type back_value(queue_ptr q) {
    return q->array[q->back_index];
}

void print(queue_ptr q) {
    printf("queue now is: ");
    int t = q->current_size;
    while (t--) {
        printf("%i ", q->array[q->front_index]);
        if (++q->front_index == q->max_size)
            q->front_index = 0;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    queue_ptr q = initialize(3);
    push(q, 10);
    push(q, 2);
    push(q, 4);
    pop(q);
    push(q, 0);
    // pop(q);
    printf("front now is: %i\n", front_value(q));
    printf("back now is: %i\n", back_value(q));
    // push(q, 1);
    // pop(q);
    // push(q, 5);
    // pop(q);
    // pop(q);
    // pop(q);
    print(q);   
    printf("size: %i\n", q->current_size);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
