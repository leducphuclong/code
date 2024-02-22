#include "stack.h"
using namespace std;

int main() {
    stack myStack(4);  // Creating a stack with a maximum size of 5

    // Pushing elements into the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    // Printing the elements in the stack
    myStack.print();

    // Checking if the stack is full
    if (myStack.isFull()) {
        cout << "Stack is full." << endl;
    } else {
        cout << "Stack is not full." << endl;
    }

    // Popping an element from the stack
    int poppedValue = myStack.pop();
    cout << "Popped value: " << poppedValue << endl;

    // Printing the elements after popping
    myStack.print();

    // Checking if the stack is empty
    if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
