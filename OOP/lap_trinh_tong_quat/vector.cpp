#include "vector.h"

template<typename element_type, int SIZE>

vector<element_type, SIZE>::vector(element_type org): size(SIZE) {
    this->data = new element_type[size];
    for (size_t i = 0; i < size; ++i)
        this->data[i] = org;
}

template<typename element_type, int SIZE>

vector<element_type, SIZE>::~vector() {
    delete[] data;
}

template<typename element_type, int SIZE>

void vector<element_type, SIZE>:: show() {
    for (int i = 0; i < this->size; ++i)
        cout << this->data[i] << endl;
}