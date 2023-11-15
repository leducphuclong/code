int main()
{
    int v{ 5 };

    int* ptr0 { &v };             // points to an "int" but is not const itself, 
    //so this is a normal pointer.
    // With normal (non-const) pointers, we can change both what the pointer
    // is pointing at (by assigning the pointer a new address to hold) or 
    // change the value at the address being held (by assigning a new value
    // to the dereferenced pointer).
    const int* ptr1 { &v };       // points to a "const int" but is not const itself, 
    // so this is a pointer to a const value.
    // The value being pointed to can't be changed, but we can change what pointer is pointing at.
    int* const ptr2 { &v };       // points to an "int" and is const itself, 
    // so this is a const pointer (to a non-const value).
    // // The value being pointed to can be changed, but we cann't change what pointer is pointing at.
    const int* const ptr3 { &v }; // points to an "const int" and is const itself, 
    //so this is a const pointer to a const value.
    // The value being pointed to cann't be changed, but we cann't change what pointer is pointing at.

    // if the const is on the left side of the *, the const belongs to the value
    // if the const is on the right side of the *, the const belongs to the pointer

    return 0;
}