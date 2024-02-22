// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

void swap(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_matrix(double mtx[][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n+1; ++j)
            printf("%.1lf ", mtx[i][j]);
        printf("\n");
    }
}

void swap_row(double mtx[][N], int n, int r1, int r2) {
    for (int j = 0; j < n+1; ++j)
        swap(&mtx[r1][j], &mtx[r2][j]);
}

void transform(double mtx[][N], int n) {
    for (int i = 0; i < n-1; ++i) {
        if (!mtx[i][i])
            for (int j = i+1; j < n; ++j)
                if (mtx[j][i]) {
                    swap_row(mtx, n, i, j);
                    break;
                }
        for (int j = i+1; j < n; ++j) {
            double m = -mtx[j][i]/mtx[i][i];
            for (int k = 0; k < n+1; ++k)
                mtx[j][k] = mtx[i][k]*m+mtx[j][k];
        }
    }
}

void solving(double mtx[][N], int n) {
    double x[N];
    for (int i = n-1; i >= 0; --i) {
        x[i] = mtx[i][n];
        for (int j = i+1; j < n; ++j)
            x[i] += mtx[i][j]*x[j];
        x[i] /= mtx[i][i];
    }
    printf("The solution of the mutli equaltion is: \n");
    for (int i = 0; i < n; ++i)
        printf("x[%i] = %lf\n", i, x[i]);
}

int main(int argc, char* argv[]) {
    // Input
    int n; double mtx[N][N];
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n+1; ++j)
            scanf("%lf", &mtx[i][j]);
    // Solve
    transform(mtx, n);
    solving(mtx, n);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
