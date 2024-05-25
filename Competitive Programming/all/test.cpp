#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<double>> Matrix;

// Function to swap rows in a matrix
void swapRows(Matrix& mat, int row1, int row2) {
    for (size_t j = 0; j < mat[0].size(); ++j) {
        double temp = mat[row1][j];
        mat[row1][j] = mat[row2][j];
        mat[row2][j] = temp;
    }
}

// Function to calculate the determinant of a matrix using determinant properties
double determinant(Matrix& mat) {
    int n = mat.size();
    if (n == 0 || mat[0].size() != n) {
        cerr << "Invalid matrix dimensions\n";
        return 0.0;
    }
    
    double det = 1.0; // Initialize determinant to 1
    for (int i = 0; i < n; ++i) {
        // If diagonal element is zero, swap rows to find non-zero element
        if (mat[i][i] == 0) {
            int nextNonZero = -1;
            for (int j = i + 1; j < n; ++j) {
                if (mat[j][i] != 0) {
                    nextNonZero = j;
                    break;
                }
            }
            if (nextNonZero == -1) {
                // No non-zero element found in the column
                return 0.0;
            }
            swapRows(mat, i, nextNonZero);
            det *= -1; // Swap of rows changes sign of determinant
        }
        // Make all elements below the diagonal as zero
        for (int j = i + 1; j < n; ++j) {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k < n; ++k) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
        det *= mat[i][i]; // Multiply determinant by diagonal element
    }
    return det;
}

int main() {
    // Example usage
    Matrix mat = {{2, 1, -3}, {0, -1, 4}, {0, 0, 5}};
    cout << "Determinant of the matrix: " << determinant(mat) << endl;
    return 0;
}
