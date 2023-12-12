#include <iostream>

class stack {
private:
    struct node {
        int element;
        node* next;
        node(const int& value) : element(value), next(nullptr) {}
    }; // this is a node in stack

    using node_ptr = node*;

    node_ptr top_node;
    unsigned int size;

public:
    stack();
    ~stack();
    void push(int element);
    int pop();
    bool isEmpty();
    unsigned int numOfElement();
    void print();
};


