// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdbool.h>

#define nln '\n'

const int N = 100;

// Declare global variables.

void get_data(double a[N], int n) {
    for (int i = 0; i < n ; ++i)
        scanf("%lf", a+i);
}

void view_array(double a[N], int n) {
    for (int i = 0; i < n; ++i)
        printf("%.1lf ", a[i]);
    printf("\n");
}

double product_of_row(int i, int n, double x[N], double c, bool print) {
    double p = 1;
    for (int idx = 0; idx < i; ++idx) {
        p *= (x[i]-x[idx]);
        if (print)
            printf("%.1lf ", x[i]-x[idx]);
    }
    p *= (c-x[i]);
    if (print)
        printf("%.1lf ", c-x[i]);
    for (int idx = i+1; idx < n; ++idx) {
        p *= (x[i]-x[idx]);
        if (print)
            printf("%.1lf ", x[i]-x[idx]);
    }
    return p;
}

double Aitken(int n, double x[N], double y[N], double c, bool print) {
    if (print)
        printf("Aitken Interpolation Table: \n");
    double w = 1, n0 = 0, D[N];
    for (int i = 0; i < n; ++i) {
        D[i] = product_of_row(i, n, x, c, print);
        w *= (c-x[i]), n0 += y[i]/D[i];
        if (print)
            printf("%.2lf \n", D[i]);
    }
    printf("\n");
    if (print) {
        printf("According to the formula: \n");
        printf("w(%.2lf) = %lf\n", c, w);
        printf("f(%.2lf) = ", c);
        printf("(");
        for (int i = 0; i < n; ++i) {
            printf("%.2lf/%.2lf", y[i], D[i]);
            if (i < n-1)
                printf(" + ");
        }
        printf(")*%lf = ", w);
    }
    return n0*w;
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n;
    double c;
    scanf("%i%lf", &n, &c);
    double x[N], y[N];
    get_data(x, n);
    get_data(y, n);
    printf("%lf\n", Aitken(n, x, y, c, 1));
    return 0;
}
