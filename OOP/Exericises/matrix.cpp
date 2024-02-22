#include <iostream>
#include <climits>
#include <algorithm>
#include <cfloat>

using namespace std;

void enter(double **&mtx, int *n, int *m) {
    cout << "Enter the n (number of rows) and m (number of columns): ";
    cin >> *n >> *m;
    cout << "OK now enter that matrix: " << endl;
    mtx = new double*[*n];
    for (int i = 0; i < *n; ++i) {
        mtx[i] = new double[*m];
        for (int j = 0; j < *m; ++j)
            cin >> *(*(mtx+i)+j);
    }
    cout << endl;
}

void view(double **&mtx, int *n, int *m) {
    cout << "This is matrix entered: " << endl;
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j)
            cout << *(*(mtx+i)+j) << ' ';
        cout << endl;
    }
    cout << endl;
}

void deallocate(double **&mtx, int *n) {
    for (int i = 0; i < *n; ++i)
        delete[] mtx[i];
    delete[] mtx;
}

void find_max_of_row(double **mtx, int n, int m) {
    for (int i = 0; i < n; ++i) {
        cout << "Max of row " << i << " : ";
        double mx = -DBL_MIN;;
        for (int j = 0; j < m; ++j)
            mx = max(mx, mtx[i][j]);
        cout << mx << endl;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    double **mtx;
    int n, m;
    enter(mtx, &n, &m);
    view(mtx, &n, &m);

    find_max_of_row(mtx, n, m);

    cout << "address before deallocate: " << mtx << endl;
    deallocate(mtx, &n);
    cout << "address after deallocate: " << mtx << endl;
    cerr << "Program finished successfully" << endl;
    return 0;
}