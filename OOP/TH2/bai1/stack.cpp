#include "stack.h"

stack::stack(): top_node(new node(0)), size(0) {
} 

stack::~stack() {
    while (!isEmpty()) {
        pop();
    }
    delete top_node; // Free the dummy node
}

void stack::push(int value) {
    node_ptr new_node = new node(value);
    if (new_node == nullptr)
        std::cerr << "Memory allocation failed!!" << std::endl;
    new_node->next = top_node->next;
    top_node->next = new_node;
    size++;
}

int stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
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
    std::cout << "stack: ";
    node_ptr itr_node = top_node->next;
    while (itr_node != nullptr) {
        std::cout << itr_node->element << ' ';
        itr_node = itr_node->next;
    }
    std::cout << std::endl;
}
