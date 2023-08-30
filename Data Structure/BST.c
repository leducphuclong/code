// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int element_type;

typedef struct node {
    element_type element;
    struct node *left, *right, *parent;
} *node_ptr;

typedef node_ptr BST;

// Constant

// Declare global variables.
// End of global variable declaration.

void postorder(BST tree) {
    if (!tree)
        return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%i ", tree->element);
}

node_ptr create(element_type element) {
    node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
    new_node->element = element;
    new_node->left = new_node->right = new_node->parent = NULL;
    return new_node;
}

BST insert(BST tree, element_type element) {
    node_ptr new_node = create(element);
    if (!tree)
        return new_node;
    node_ptr itr = tree, prev;
    while (itr != NULL) {
        prev = itr;
        if (element < itr->element)
            itr = itr->left;
        else if (element > itr->element)
            itr = itr->right;
        else
            return tree;
    }
    new_node->parent = prev;
    if (prev->left == NULL)
        prev->left = new_node;
    else
        prev->right = new_node;
    return tree;
}

node_ptr min_node(BST tree) {
    if (!tree)
        return NULL;
    if (!tree->left)
        return tree;
    return min_node(tree->left);
}

node_ptr find(BST tree, element_type element) {
    if (!tree)
        return NULL;
    if (element < tree->element)
        return find(tree->left, element);
    else if (element > tree->element)
        return find(tree->right, element);
    else
        return tree;
}

node_ptr successor(BST tree, node_ptr x) {
    if (!tree || !x)
        return NULL;
    if (x->right)
        return min_node(x->right);
    node_ptr px = x;
    while (px != NULL && px->parent->right == px)
        px = px->parent;
    if (px == NULL)
        return NULL;
    return px->parent;
}

BST delete(BST tree, node_ptr x) {
    if (!tree || !x)
        return tree;
    node_ptr y;
    if (!x->left || !x->right)
        y = x;
    else
        y = successor(tree, x);
    node_ptr child;
    if (y->left != NULL)
        child = y->left;
    else
        child = y->right;

    if (child)
        child->parent = y->parent;

    if (!y->parent) {
        tree = child;
    } else {
        if (y->parent->left == y)
            y->parent->left = child;
        else
            y->parent->right = child;
    }

    return tree;
}

int main(int argc, char* argv[]) {
    BST tree = insert(tree, 8);
    tree = insert(tree, 4);
    tree = insert(tree, 3);
    tree = insert(tree, 6);
    tree = insert(tree, 5);
    tree = insert(tree, 7);
    tree = insert(tree, 1);
    printf("test successor %i\n", successor(tree, find(tree, 5))->element);
    tree = delete(tree, find(tree, 8));
    tree = delete(tree, find(tree, 7)); 
    tree = delete(tree, find(tree, 8));
    tree = delete(tree, find(tree, 1));
    tree = delete(tree, find(tree, 5));
    // tree = delete(tree, find(tree, 3));
    // tree = delete(tree, find(tree, 6));
    // tree = delete(tree, find(tree, 4));
    postorder(tree);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
