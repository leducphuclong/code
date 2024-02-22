#include <iostream>

class stack {
private:
    struct node {
        int element;
        unsigned int index;
        node* next;
        // Constructors
        node(const int& value);
        node(const int& value, unsigned int idx, node* nxt);
        // Destructor
        ~node();
        void print_node();
    };

    using node_ptr = node*;

    static unsigned int id;

    node_ptr top_node;
    unsigned int size;
    const unsigned max_size;

public:
    stack(unsigned int maxSize = 10);
    ~stack();
    void push(int element);
    int pop();
    bool isEmpty();
    unsigned int numOfElement();
    void print();
    bool isFull();
};


