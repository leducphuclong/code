// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef char element_type;

typedef struct node {
    element_type element;
    struct node *next;
} *node_ptr;

typedef node_ptr stack;

// Constant

// Declare global variables.
// End of global variable declaration.

stack initialize() {
    stack s = (stack)malloc(sizeof(struct node));
    s->next = NULL;
    return s;
}

void Error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

bool empty(stack s) {
    return s->next == NULL;
}

void push(element_type e, stack s) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = e;
    new_node->next = s->next;
    s->next = new_node;
}

void pop(stack s) {
    if (empty(s))
        Error("Stack is now empty, can not continue to pop.");
    node_ptr tmp_node = s->next;
    s->next = s->next->next;
    free(tmp_node);
}

element_type top(stack s) {
    return s->next->element;
}

bool is_sign(char ch) {
    char* sign = "+-*/()";
    for (int i = 0; i < 6; ++i)
        if (sign[i] == ch)
            return true;
    return false;
}

bool is_priority(char ch) {
    return ch == '*' || ch == '/';
}

void print_stack(stack s) {
    node_ptr itr_node = s;
    while (itr_node->next != NULL) {
        printf("%c ", itr_node->next->element);
        itr_node = itr_node->next;
    }
    printf("\n");
}

char* concatenate_char(char* str, char ch) {
    int l = strlen(str);
    char* result = (char*)malloc(sizeof(char)*(l+2));
    strcpy(result, str);
    result[l] = ch;
    result[l+1] = '\0';
    return result;
}

int main(int argc, char* argv[]) {
    freopen("out", "w", stdout);
    char* infix = "a+b*c+d*e+((f+g/h)-t)*u";
    char* postfix = "";
    int l = strlen(infix);
    stack s = initialize();
    for (int i = 0; i < l; ++i) {
        if (!is_sign(infix[i])) {
            postfix = concatenate_char(postfix, infix[i]);
        } else {
            if (infix[i] == ')') {
                while (!empty(s) && top(s) != '(') {
                    postfix = concatenate_char(postfix, top(s));
                    pop(s);
                }
                if(!empty(s))
                    pop(s);
            } else if (is_priority(infix[i]) || infix[i] == '(') {
                push(infix[i], s);
            } else {
                while (!empty(s) && top(s) != '(' && is_priority(top(s))) {
                    postfix = concatenate_char(postfix, top(s));
                    pop(s);
                }
                push(infix[i], s);
            }
        }
    }
    while (!empty(s)) {
        postfix = concatenate_char(postfix, top(s));
        pop(s);
    }
    printf("%s\n", postfix);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
