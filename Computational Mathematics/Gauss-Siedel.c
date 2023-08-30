// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <math.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant
const double EPS = 1e-6;

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

void solve(double mtx[][N], int n, double x[]) {
    double y[N];
    bool stop;
    do {
        stop = 1;
        for (int i = 0; i < n; ++i) {
            if (!mtx[i][i])
            for (int j = i+1; j < n; ++j)
                if (mtx[j][i]) {
                    swap_row(mtx, n, i, j);
                    break;
                }
            double s = 0;
            for (int j = 0; j < n; ++j)
                if (j != i)
                    s += mtx[i][j]*x[j];
            y[i] = (mtx[i][n]-s)/mtx[i][i];
            if (fabs(y[i]-x[i]) >= EPS)
                stop = 0;
        }
        for (int i = 0; i < n; ++i)
            x[i] = y[i];
    } while (!stop);
    printf("The Solution of the multi equaltion is: \n");
    for (int i = 0; i < n; ++i)
        printf("x[%i] = %lf", i, x[i]);
}

int main(int argc, char* argv[]) {
    // Input
    int n; double mtx[N][N];
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n+1; ++j)
            scanf("%lf", &mtx[i][j]);
    // Solve
    double x0[] = {0, 0, 0};
    int nx0 = sizeof(x0)/sizeof(double);
    solve(mtx, n, x0);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
