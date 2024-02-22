#include "stack.h"
#include <iostream>

using namespace std;

stack::node::node(const int& value) : element(value), index(id), next(nullptr) {
    id++;
}

stack::node::node(const int& value, unsigned int idx, node* nxt) : element(value), index(idx), next(nxt) {}

stack::node::~node() {
}

void stack::node::print_node() {
    cout << index << '\t' << element << '\n';
}

unsigned int stack::id = 0;

stack::stack(unsigned int maxSize) : max_size(maxSize), top_node(new node(0)), size(0) {}

stack::~stack() {
    while (!isEmpty()) {
        pop();
    }
    delete top_node; // Free the dummy node
}

void stack::push(int value) {
    if (isFull() == true) {
        cout << "Stack is full, cannot push more than " << max_size << " element !!" << endl;
        return;
    }
    node_ptr new_node = new node(value);
    if (new_node == nullptr)
        cerr << "Memory allocation failed!!" << endl;
    new_node->next = top_node->next;
    top_node->next = new_node;
    size++;
}

int stack::pop() {
    if (isEmpty()) {
        cerr << "Stack is empty!" << endl;
        return 0; // Return a default value for the element type
    }

    node_ptr tmp_node = top_node->next;
    top_node->next = tmp_node->next;
    int tmp_value = tmp_node->element;
    delete tmp_node;
    size--;
    return tmp_value;
}

bool stack::isEmpty() {
    return size == 0;
}

unsigned int stack::numOfElement() {
    return size;
}

void stack::print() {
    cout << "stack: \n";
    node_ptr itr_node = top_node->next;
    while (itr_node != nullptr) {
        itr_node->print_node();
        itr_node = itr_node->next;
    }
    cout << endl;
}

bool stack::isFull() {
    return size == max_size;
}
