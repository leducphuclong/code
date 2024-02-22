// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <math.h>
#include <limits.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant
const double EPS = 1e-6;

// Declare global variables.
// End of global variable declaration.

void print_matrix(double mtx[][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n+1; ++j)
            printf("%.1lf ", mtx[i][j]);
        printf("\n");
    }
}

void multi_matrix(double a[][N], double b[][N], double c[][N], int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k)
                c[i][j] += a[i][k]*b[k][j];
        }
}

void solve(double mtx[][N], int n) {
    double M[N][N], M1[N][N];
    for (int k = n-2; k >= 0; --k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != k) {
                    if (i == j)
                        M[i][j] = M1[i][j] = 1;
                    else
                        M[i][j] = M1[i][j] = 0;
                } else {
                    M1[i][j] = mtx[k+1][j];
                    if (j == k)
                        M[i][j] = (double)1/mtx[k+1][k];
                    else
                        M[i][j] = -mtx[k+1][j]/mtx[k+1][k];
                }
        double tmp[N][N];
        multi_matrix(mtx, M, tmp, n);
        multi_matrix(M1, tmp, mtx, n);
    }
    print_matrix(mtx, n);
}

int main(int argc, char* argv[]) {
    // Input
    int n; double mtx[N][N];
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &mtx[i][j]);
    // Solve
    solve(mtx, n);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
