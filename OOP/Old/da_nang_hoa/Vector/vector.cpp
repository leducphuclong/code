#include "vector.h"

vector::vector(unsigned n, double v) {
    if (this->address == NULL) 
        return;
    size = n;
    address = new double[n];
    for (int i = 0; i < size; i++)
        *(address+i) = v;
}   

vector::~vector() {
    delete[] this->address;
}

void vector::view() {
    for (int i = 0; i < this->size; i++)
        cout << *(this->address+i) << ' ';
    cout << endl;
}

istream& operator>>(istream& inp, vector& v) {
    cout << "Enter a vector with " << v.size << " elements: ";
    for (int i = 0; i < v.size; ++i)
        inp >> v[i];
    return inp;
}
ostream& operator<<(ostream& out, const vector& v){
    for (int i = 0; i < v.size; i++)
        out << v.address[i] << ' ';
    return out;
}

double& vector::operator[](unsigned i) {
    return *(this->address+i);
}

vector::vector(const vector& vt) {
    if (this->address == NULL)
        return;
    this->size = vt.size;
    this->address = new double[this->size];
    for (int i = 0; i < this->size; i++)
        (*this)[i] = *(vt.address+i);
}

const vector& vector::operator=(const vector &vt) {
    if (this != &vt) {
        delete [] this->address;
        this->size = vt.size;
        this->address = new double[this->size];
        for (int i = 0; i < this->size; ++i)
            (*this)[i] = *(vt.address+i);
    }
    return *this;
}