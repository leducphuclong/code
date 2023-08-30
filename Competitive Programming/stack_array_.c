// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define nln '\n'
#define EMPTY_TOP (-1)
#define MIN_STACK_SIZE (1)

// Declare global variables.

typedef struct Element_type {
    char value;
} element_type;

struct stack_record {
    unsigned int capacity;
    int top_of_stack;
    element_type *stack_array;
};

typedef struct stack_record *STACK;

STACK initialize(unsigned int max_elements) {
    STACK stack;
    if (max_elements < MIN_STACK_SIZE) {
        printf("Stack size <= 0 !! \n");
        return stack;
    }
    stack = (STACK)malloc(sizeof(struct stack_record));
    if (stack == NULL) {
        printf("Memory error ! \n");
        return stack;
    }
    stack->stack_array = (element_type*)
    malloc(sizeof(element_type)*max_elements);
    if (stack->stack_array == NULL) {
        printf("Memory error ! \n");
        return stack;
    }
    stack->top_of_stack = EMPTY_TOP;
    stack->capacity = max_elements;
    return stack;
}

void dispose(STACK stack) {
    if (stack != NULL) {
        free(stack->stack_array);
        free(stack);
    }
}

bool is_empty(STACK stack) {
    return (stack->top_of_stack == EMPTY_TOP);
}

void make_null(STACK stack) {
    stack->top_of_stack = EMPTY_TOP;
}

bool is_full(STACK stack) {
    return stack->capacity == stack->top_of_stack+1;
}

void push(STACK stack, element_type e) {
    if (is_full(stack))
        return;
    stack->stack_array[++stack->top_of_stack] = e;
}

element_type top(STACK stack) {
    if (is_empty(stack))
        printf("Stack is empty !! \n");
    else
        return stack->stack_array[stack->top_of_stack];
}

void pop(STACK stack) {
    if (is_empty(stack)) {
        printf("Stack is empty !! \n");
        return;
    }
    stack->top_of_stack--;
}

void print_stack(STACK stack) {
    int idx = stack->top_of_stack;
    while (idx >= 0)
        printf("%c\n", stack->stack_array[idx--]);
}

bool in(char *str, char c) {
    for (int i = 0; i < strlen(str); ++i)
        if (str[i] == c)
            return 1;
    return 0;
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    char *str = "{}()[]";
    printf("%s\n", str);

    printf("len: %i\n", strlen(str));
    STACK stack = initialize(strlen(str));
    for (int i = 0; i < strlen(str); ++i)
        if (!in(stack, str[i])) {
            element_type e;
            printf("%c", str[i]);
            e.value = (char)str[i];
            push(stack, e);
        }
    print_stack(stack);
    printf("\ngood for now ! \n");
    return 0;
}
