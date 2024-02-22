#include "vector.h"

vector::vector(int n, int v) {
    this->size = n;
    this->data = new int[n];
    for (int i = 0; i < n; i++)
        (*this)[i] = v;
}

vector::vector(const vector& p) {
    *this = p;
}

vector::~vector() {
    delete [] data;
}

ostream& operator<<(ostream& out, const vector& v) {
    out << "Vector contains these values: ";
    for (int i = 0; i < v.size; i++)
        out << v[i] << ' ';
    out << endl;
    return out;
}

void vector::view() {
    cout << "Vector contains these values: ";
    for (int i = 0; i < this->size; i++)
        cout << (*this)[i] << ' ';
    cout << endl;
}

int& vector::operator[](int i) const {
    return *(this->data+i);
}

void vector::operator=(const vector& p) {
    delete [] this->data;
    this->size = p.size;
    this->data = new int[this->size];
    for (int i = 0; i < this->size; i++)
        (*this)[i] = p[i];
}




