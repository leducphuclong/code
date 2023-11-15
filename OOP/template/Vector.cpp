#include "Vector.h"

template<typename T> 
Vector<T>::Vector() {
    cout << "Vector Constructed !!" << endl;
}

// template<typename T>
// Vector<T>:: Vector(int n): size(n){ 
//     this->data = new T[this->size];
//     for (int i = 0; i < n; ++i)
//         cin >> *(this->data + i);

// }

template<typename T>
Vector<T>::~Vector() {
    delete [] this->data;
    cout << "Vector Deconstructed !!" << endl;
}

template<typename T>
ostream& operator<<(ostream& o, const Vector<T>& v) {
    o << "Vector contains: ";
    for (int i = 0; i < v.size; ++i)
        o << *(v.data + i) << ' ';
    o << endl;
    return o;
}