#include "matrix.h"

int matrix::GarbageValue = 0;

matrix::matrix(int row, int col, int value):
NoRow(row), NoColumn(col) {
    this->data = new int*[row];
    for (int i = 0; i < NoRow; i++) {
        *((this->data)+i) = new int[NoColumn];
        for (int j = 0; j < NoColumn; j++)
            *(*(this->data+i)+j) = value;
    }

matrix::~matrix() {
    for (int i = 0; i < NoRow; i++) {
        delete [] this->data[i];
    }
}

void matrix::display() const {
    cout << "Display matrix: " << endl;
    for (int i = 0; i < NoColumn; i++) {
        for (int j = 0; j < NoColumn; j++)
            cout << *(*(data+i)+j) << ' ';
        cout << endl;
    }
}

ostream& operator<<(ostream& op, const matrix& mtx) {
    /*  returning a reference to the stream from operator<< enables chaining  */
    op << "Display matrix: " << endl;
    for (int i = 0; i < mtx.NoRow; i++) {
        for (int j = 0; j < mtx.NoColumn; j++)
            op << *(*(mtx.data+i)+j) << ' ';
        op << endl;
    }
    return op;
}

int& matrix::operator()(int iRow, int iCol) {
    return (iRow >= 0 && iRow < this->NoRow && iCol >= 0 && iCol < this->NoColumn)
    ? (*(*(data+iRow)+iCol)) : GarbageValue;
}