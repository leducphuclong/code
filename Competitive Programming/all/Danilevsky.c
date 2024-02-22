// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <string.h>

#define nln '\n'
#define N 100

// Declare global variables.

void input(int *n, double a[][N]) {
    *n = 4;
    double b[N][N] = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {4, 5, 7, 8},
        {3, 4, 5, 6}
    };
    for (int i = 0; i < *n; ++i)
        for (int j = 0; j < *n; ++j)
            a[i][j] = b[i][j];
}

void multiply(int n, double a[][N], double b[][N], double c[][N]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k)
                c[i][j] += a[i][k]*b[k][j];
        }
}

void print_array(int n, double a[][N]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%.1llf ", a[i][j]);
        printf("\n");
    }
    printf("---------------------------------------------\n");
}

void Danilevsky(int n, double a[][N]) {
    double m[N][N], m1[N][N];
    print_array(n, a);
    for (int k = n-2; k >= 0; --k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != k) {
                    if (i == j)
                        m[i][j] = 1, m1[i][j] = 1;
                    else
                        m[i][j] = 0, m1[i][j] = 0;
                } else {
                    m1[i][j] = a[k+1][j];
                    if (j == k)
                        m[i][j] = 1/a[k+1][k];
                    else
                        m[i][j] = -a[k+1][j]/a[k+1][k];
                }
        double tm[N][N];
        multiply(n, m1, a, tm);
        multiply(n, tm, m, a);
        printf("A%i: \n", n-k-1);
        print_array(n, a);
    }
}

int main(int argc, char* argv[]) {
    int n;
    double a[N][N];
    input(&n, a);
    Danilevsky(n, a);
    print_array(n, a);
    return 0;
}
