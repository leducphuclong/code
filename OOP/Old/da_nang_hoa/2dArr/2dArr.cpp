#include "2dArr.h"

Matrix::Matrix(int r, int c, int v): row(r), col(c){
    this->p = new int*[this->row];
    for (int i = 0; i < this->row; ++i) {
        *(p+i) = new int[this->col];
        for (int j = 0; j < this->col; ++j)
            *(*(this->p+i)+j) = v;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->row; ++i)
        delete[] this->p[i];
    delete[] this->p;
}

void Matrix::Show() {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j)
            cout << *(*(this->p+i)+j);
        cout << endl;
    }
}

ostream& operator<<(ostream& o, const Matrix& m) {
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.col; ++j)
            o << *(*(m.p+i)+j) << ' ';
        o << endl;
    }
    return o;
}

int& Matrix::operator()(const int& i, const int& j) {
    static int er = -1;
    return (0 <= i && i < this->row && 0 <= j && j < this->col) ? *(*(p+i)+j) : er;
}