// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nln '\n'
#define EMPTY_SIGNAL -1
#define MIN_STACK_SIZE 1

// Declare global variables.

typedef int element_type;
typedef element_type *element_type_ptr;

struct stack_record {
    unsigned int stack_size;
    int top_position;
    element_type *stack_array;
};

typedef struct stack_record *stack_ptr;

void Error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

stack_ptr CreateStack(unsigned stack_size) {
    if (stack_size < MIN_STACK_SIZE)
        Error("Stack size is too small!");
    stack_ptr tmp_stack = (stack_ptr)malloc(sizeof(struct stack_record));
    if (tmp_stack == NULL)
        Error("Memory Allocation Failed!");
    tmp_stack->stack_size = stack_size;
    tmp_stack->top_position = EMPTY_SIGNAL;
    tmp_stack->stack_array = (element_type_ptr)malloc(sizeof(element_type)
        *stack_size);
    if (tmp_stack->stack_array == NULL)
        Error("Memory Allocation Failed!");
    return tmp_stack;
}

void Dispose(stack_ptr stack) {
    if (stack != NULL) {
        free(stack->stack_array);
        free(stack);
    }
}

bool IsEmpty(stack_ptr stack) {
    return stack->top_position == EMPTY_SIGNAL;
}

void MakeNULL(stack_ptr stack) {
    stack->top_position = EMPTY_SIGNAL;
}

bool IsFull(stack_ptr stack) {
    return stack->top_position >= (int)stack->stack_size-1;
}

void Push(stack_ptr stack, element_type element) {
    if (IsFull(stack))
        Error("Stack is full, can not continue to push!");
    stack->stack_array[++stack->top_position] = element;
}

element_type Top(stack_ptr stack) {
    if (IsEmpty(stack))
        Error("Stack is empty, can not take the top!");
    return stack->stack_array[stack->top_position];
}

void Pop(stack_ptr stack) {
    if (IsEmpty(stack))
        Error("Stack is empty, can not pop!");
    stack->top_position--;
}

int main(int argc, char* argv[]) {
    stack_ptr stack = CreateStack(10);
    Push(stack, 2);
    Push(stack, 5);
    printf("%i\n", Top(stack));
    Pop(stack);
    printf("%i\n", Top(stack));
    Pop(stack);
    printf("%i\n", Top(stack));
    return 0;
}
