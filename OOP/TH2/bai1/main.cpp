#include "stack.h"

int main() {
    stack intStack;

    // Push elements onto the stack
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    // Print the stack
    intStack.print();

    // Pop an element
    int poppedElement = intStack.pop();
    std::cout << "Popped element: " << poppedElement << std::endl;

    // Print the stack after popping
    intStack.print();

    // Check if the stack is empty
    std::cout << "Is the stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << std::endl;

    // Get the number of elements in the stack
    std::cout << "Number of elements in the stack: " << intStack.numOfElement() << std::endl;

    return 0;
}
