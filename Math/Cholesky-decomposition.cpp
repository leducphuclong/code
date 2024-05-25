// Le Duc Phuc Long, 2024, 20 yo
// You don't think twice, you code twice

/*
Phân rã Cholesky là một phương pháp phân rã một ma trận vuông, xác định dương xác định, thành một tích của một ma trận tam giác dưới và ma trận chuyển vị của nó. Điều kiện để một ma trận vuông \( A \) có thể được phân rã theo Cholesky là:

1. **Đối xứng và xác định dương**: Ma trận \( A \) phải là ma trận vuông đối xứng (\( A = A^T \)) và xác định dương, tức là tất cả các phần tử trên đường chéo chính phải lớn hơn 0 và ma trận con chính cho bởi bất kỳ tập hợp nào của các hàng và cột phải là xác định dương.

2. **Không có ma trận con chính nào không xác định dương**: Mọi ma trận con chính của \( A \) phải là xác định dương. Điều này đảm bảo rằng không có vấn đề về tính không chính xác hoặc không xác định khi thực hiện phân rã Cholesky.

3. **Ma trận không suy biến**: Ma trận \( A \) không được suy biến, tức là nó phải có hạng bằng số hàng hoặc số cột của nó.

Nếu tất cả các điều kiện trên được đáp ứng, thì ma trận \( A \) có thể được phân rã theo phương pháp Cholesky thành một ma trận tam giác dưới \( L \), sao cho \( A = LL^T \), trong đó \( L \) là ma trận tam giác dưới.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<vector<db>> matrix;

#define nln '\n'

void enterMatrix(matrix &mtx, ll &n) {
    cout << "Enter the size of matrix: ";
    cin >> n;
    mtx.resize(n, vector<db>(n));
    cout << "Enter Matrix: " << nln;
    for (auto &row : mtx)
        for (auto &val : row)
            cin >> val;
}

void viewMatrix(const matrix &arr) {
    for (auto row : arr) {
        for (auto val : row)
            cout << setw(6) << val << '\t';
        cout << endl;
    }
}

matrix Cholesky_Decomposition(const matrix& A) {
    ll n = A.size();
    matrix L(n, vector<db>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) {
            if (i == j) {
                db sum = 0;
                for (int k = 0; k < i; ++k)
                    sum += L[i][k]*L[i][k];
                L[i][j] = sqrt(A[i][j] - sum);
            } else {
                db sum = 0;
                for (int k = 0; k < j; ++k)
                    sum += L[i][k]*L[j][k];
                L[i][j] = (A[i][j] - sum)/L[j][j];
            }
        }
    return L;
}

bool isSymmetric(const matrix& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i][j] != A[j][i]) {
                return false;
            }
        }
    }
    return true;
}

double determinantNxN(const matrix& mtx) {
    int n = mtx.size();
    
    // Base case: if the matrix is 1x1, return the single element
    if (n == 1) {
        return mtx[0][0];
    }

    double det = 0;
    int sign = 1;

    // Iterate over the first row to calculate the determinant
    for (int i = 0; i < n; ++i) {
        // Calculate the minor matrix by excluding the current row and column
        matrix minor(n - 1, vector<double>(n - 1));
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (k < i) {
                    minor[j - 1][k] = mtx[j][k];
                } else if (k > i) {
                    minor[j - 1][k - 1] = mtx[j][k];
                }
            }
        }

        // Calculate the determinant recursively for the minor matrix
        double minorDet = determinantNxN(minor);

        // Add the contribution of the current element to the determinant
        det += sign * mtx[0][i] * minorDet;

        // Alternate the sign for each element in the first row
        sign *= -1;
    }

    return det;
}

bool isPositiveDefinite(const matrix& A) {
    // Check if the matrix is symmetric
    if (!isSymmetric(A)) {
        return false;
    }

    // Check if all leading principal minors are positive
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        matrix submatrix(i + 1, vector<double>(i + 1));
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i; ++k) {
                submatrix[j][k] = A[j][k];
            }
        }

        if (determinantNxN(submatrix) <= 0) {
            return false;
        }
    }
    return true;
}

db sqr(db x) {
    return x*x;
}

void LDLT_Decomposition(const matrix& A, matrix &L, matrix& D) {
    matrix C = Cholesky_Decomposition(A);
    int n = A.size();
    L = matrix(n, vector<db>(n, 0));
    D = matrix(n, vector<db>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i == j)
                D[i][j] = sqr(C[i][j]),
                L[i][j] = 1;
            else {
                L[i][j] = A[i][j]*pow(D[i][i], -0.5);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // Example matrix
    // matrix A = {
    //     {2, 4, 3, 5},
    //     {-4, -7, -5, -8},
    //     {6, 8, 2, 9},
    //     {4, 9, -2, 14}
    // };
    matrix A = { { 4, 12, -16 },
                 { 12, 37, -43 },
                 { -16, -43, 98 } };

    if (isPositiveDefinite(A)) {
        matrix L = Cholesky_Decomposition(A);
        cout << "L matrix:" << endl;
        viewMatrix(L);
        cout << endl;   
    } else {
        cout << "The matrix is not positive definite." << endl;
    }

    return 0;
}