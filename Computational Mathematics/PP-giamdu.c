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

void solve(double mtx[][N], int n, double x[]) {
    for (int i = 0; i < n; ++i) {
        double tmp = mtx[i][i];
        for (int j = 0; j < n+1; ++j)
            mtx[i][j] = mtx[i][j]/tmp;
    }
    // Tinh cac so du ban dau
    double r[N];
    for (int i = 0; i < n; ++i) {
        r[i] = mtx[i][n];
        for (int j = 0; j < n; ++j)
            r[i] -= mtx[i][j]*x[j];
    }

    bool stop;
    do {
        stop = 1;
        // Tim ri max de tinh lai
        double mav = 0;
        int loc = 0;
        for (int i = 0; i < n; ++i) {
            if (fabs(r[i]) > fabs(mav)) {
                mav = r[i];
                loc = i;
            }
        }
        x[loc] += r[loc];
        // Tinh lai 
        double tmp = r[loc];
        for (int i = 0; i < n; ++i) {
            r[i] -= mtx[i][loc]*tmp;
            if (r[i] >= EPS)
                stop = 0;
        }
    } while (!stop);

    printf("The Solution of the multi equaltion is: \n");
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
    double x0[] = {0, 0, 0};
    int nx0 = sizeof(x0)/sizeof(double);
    solve(mtx, n, x0);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
