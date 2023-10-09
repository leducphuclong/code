#include <iostream>

using namespace std;

class Matrix {
    private:
        int **p, row, col;
    public:
        Matrix(int = 2, int = 3, int = 1);
        ~Matrix();
        friend ostream& operator<<(ostream&, const Matrix&);
        void Show();
        int& operator()(const int&, const int&);
};