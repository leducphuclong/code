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

typedef struct tree_node {
    element_type element;
    struct tree_node *left, *right, *parent;
} *tree_node_ptr;

typedef tree_node_ptr TREE;

typedef struct stack_node {
    TREE tree;
    struct stack_node *next;
} *stack_node_ptr;

typedef stack_node_ptr STACK;

// Constant

// Declare global variables.
// End of global variable declaration.

void Error(const char* message) {
    printf("%s\n", message);
    exit(1);
}

STACK initialize_stack() {
    STACK s = (STACK)malloc(sizeof(struct stack_node));
    s->next = NULL;
}

bool empty_stack(STACK s) {
    return s->next == NULL;
}

void push_in_stack(STACK s, TREE t) {
    // Attach data of element
    stack_node_ptr new_stack_node = (stack_node_ptr)malloc(sizeof(struct stack_node));
    // Linking
    new_stack_node->tree = t;
    new_stack_node->next = s->next;
    s->next = new_stack_node;
}

void pop_out_stack(STACK s) {
    if (empty_stack(s))
        Error("This stack is now empty, can not continue to pop!");
    stack_node_ptr tmp = s->next;
    s->next = s->next->next;
    free(tmp);
}

TREE top_of_stack(STACK s) {
    if (empty_stack(s))
        Error("This stack is now empty, so there is no top to take.");
    return s->next->tree;
}

tree_node_ptr create_tree_node(element_type element) {
    tree_node_ptr new_tree_node = (tree_node_ptr)malloc(sizeof(struct tree_node));
    new_tree_node->element = element;
    new_tree_node->left = NULL;
    new_tree_node->right = NULL;
    new_tree_node->parent = NULL;
    return new_tree_node;
}

bool sign(char ch) {
    char* sign = "+-*/";
    for (int i = 0; i < 4; ++i)
        if (ch == sign[i])
            return true;
    return false;
}

bool priority(char ch) {
    return ch == '/' || ch == '*';
}

bool requires_parentheses(TREE tree) {
    // This node tree is a operand
    if (tree->left == NULL && tree->right == NULL)
        return false;
    // This is a operator '*' or '/'
    if (priority(tree->element)) {
        return false;
    } else {  // This is operator '+' or '-'
        // But its parents is a '*' or '/'
        if (tree->parent != NULL && priority(tree->parent->element))
            return true;
        else  // its parents is a '+' or '-'
            return false;
    }
}

void inorder_traversal(TREE tree) {
    if (tree == NULL)
        return;

    if (requires_parentheses(tree))
        printf("(");
    inorder_traversal(tree->left);

    printf("%c", tree->element);

    inorder_traversal(tree->right);
    if (requires_parentheses(tree))
        printf(")");
}

int main(int argc, char* argv[]) {
    // Input
    freopen("out", "w", stdout);
    char* postfix = "abc*de*fgh/+t-u*+++";  // abc*de*f+g*++
    int l = strlen(postfix);
    // Solve
    STACK s = initialize_stack();
    for (int i = 0; i < l; ++i) {
        tree_node_ptr new_tree_node = create_tree_node(postfix[i]);
        if (!sign(postfix[i])) {
            push_in_stack(s, new_tree_node);
        } else {
            new_tree_node->right = top_of_stack(s);
            top_of_stack(s)->parent = new_tree_node;
            pop_out_stack(s);

            new_tree_node->left = top_of_stack(s);
            top_of_stack(s)->parent = new_tree_node;
            pop_out_stack(s);

            push_in_stack(s, new_tree_node);
        }
    }
    inorder_traversal(top_of_stack(s));
    printf("\n");
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
