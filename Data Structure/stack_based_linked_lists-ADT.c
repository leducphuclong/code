// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>

// Abstract Data Types of Stack

#include <stdio.h>
#include <stdlib.h> 

#include <stdbool.h>

#define nln '\n'

// Declare global variables.

typedef int element_type;

typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef struct node stack;

typedef stack *stack_ptr;

void Error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

stack_ptr Initialize(stack_ptr s) {
    node_ptr header_node = (node_ptr)malloc(sizeof(struct node));
    if (header_node == NULL)
        Error("Memory Allocation Fail!");
    header_node->next = NULL;
    return header_node;
}

bool IsEmpty(stack_ptr s) {
    return s->next == NULL;
}

void MakeNULL(stack_ptr s) {
    s->next = NULL;
}

void Print(stack_ptr s) {
    node_ptr itr_node = s;
    while (itr_node->next != NULL) {
        printf("%i ", itr_node->next->element);
        itr_node = itr_node->next;
    }
    printf("\n");
}

void Insert(stack_ptr s, element_type element) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    if (new_node == NULL)
        Error("Memory Allocation Fail!");
    new_node->element = element;
    new_node->next = s->next;
    s->next = new_node;
}

element_type Top(stack_ptr s) {
    if (IsEmpty(s))
        Error("Stack is empty!");
    return s->next->element;
}

void Pop(stack_ptr s) {
    if (IsEmpty(s))
        Error("Stack is empty!");
    node_ptr tmp_node = s->next;
    s->next = s->next->next;
    free(tmp_node);
}
 
bool Is_in(element_type element, stack_ptr s) {
    node_ptr itr_node = s;
    while (itr_node->next != NULL) {
        if (itr_node->next->element == element)
            return true;
        itr_node = itr_node->next;
    }
    return false;
}

int main(int argc, char* argv[]) {
    stack_ptr s;
    s = Initialize(s);
    Insert(s, 1);
    Print(s);
    printf("%i\n", Top(s));
    Pop(s);
    printf("After poping: \n");
    printf("hi");
    Print(s);
    return 0;
}
