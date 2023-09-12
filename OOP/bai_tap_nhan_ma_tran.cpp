#include <iostream>

using namespace std;

double** allocation(double **arr, int &r, int &c) {
    cout << "row: "; cin >> r;
    cout << "column: "; cin >> c;
    cout << "Enter the matrix row by row: " << endl;
    arr = new double*[r];
    for (int i = 0; i < r; i++)
        *(arr+i) = new double[c];
    return arr;
}

void enter(double **arr, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> (*(*(arr+i)+j));
}

void show(double **arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << (*(*(arr+i)+j)) << ' ';
        cout << endl;
    }
}

double* min_itr(double *arr, int n) {
    double *itr = arr;
    double miv = 99999;
    for (int i = 0; i < n; i++) {
        if (*(arr+i) < miv) {
            miv = *(arr+i);
            itr = arr+i;
        }
    }
    return itr;
}

double* max_itr(double *arr, int n) {
    double *itr = arr, mav = -99999;
    for (int i = 0; i < n; i++) {
        if (*(arr+i) > mav) {
            mav = *(arr+i);
            itr = arr+i;
        }
    }
    return itr;
}

void answer(double **arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        cout << "In the line " << i << ": " << endl;
        cout << "The max element of line " << i << " is " << *max_itr(*(arr+i), c) << endl;
        cout << "The min element of line " << i << " is " << *min_itr(*(arr+i), c) << endl;
    }
}

void reallocation(double **arr, int r, int c) {
    for (int i = 0; i < r; ++i) {
        delete[] *(arr+i);
    }
    delete[] arr;
}

int main() {
    double **arr;
    int r, c;
    arr = allocation(arr, r, c);
    enter(arr, r, c);
    cout << "The matrix is: " << endl;
    show(arr, r, c);
    cout << endl;
    answer(arr, r, c);
    reallocation(arr, r, c);
    show(arr, r, c);
    return 0;
}