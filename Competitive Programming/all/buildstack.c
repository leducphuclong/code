// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nln '\n'

// Declare global variables.

struct element_type {
    int value;
};

typedef struct element_type element;

typedef struct node *node_ptr;

struct node {
    element e;
    node_ptr next;
};

typedef node_ptr stack;

stack create_stack() {
    stack s;
    s = (stack)malloc(sizeof(struct  node));
    s->next == NULL;
    if (s == NULL)
        printf("Out of space!\n");
    printf("address of s: %p\n", *(s->next));
    return s;
}

void push(stack s, element e) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Out of space!\n");
        return;
    }
    new_node->e = e;
    new_node->next = s->next;
    s->next = new_node;
}

bool empty(stack s) {
    return s->next == NULL;
}

element pop(stack s) {
    if (empty(s)) {
        element e;
        return e;
    }
    node_ptr tmp = s->next;
    s->next = s->next->next;
    element tpe = tmp->e;
    free(tmp);
    return tpe;
}

void clear(stack s) {
        printf("hi\n");
    printf("%p\n", s->next);
        return;
    while (!empty(s)) {
        printf("hi\n");
        pop(s);
    }
}

int main(int argc, char* argv[]) {
    element e1, e2;
    e1.value = 10;
    e2.value = 20;
    stack s = create_stack();
    // s->next = NULL;
    printf("s: %p\n", s->next);
    //push(s, e1);
    //push(s, e2);
    //printf("hi: %i\n", pop(s).value);
    //printf("hi: %i\n", pop(s).value);
    clear(s);
    //printf("top: %i\n", s->next->e.value);
    printf("Good for now\n");
    return 0;
}
