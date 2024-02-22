#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

const double eps = 1e-4;

double g(double x) {
    return pow(x+1, 1/3.0);
}

double No(bool *check, double x, double a, double b) {
    if (x < a || x > b) {
        *check = false;
        return -1;
    }
    double xs = g(x), d = 100000;
    while (fabs(xs-x) < d && fabs(xs-x) >= eps) {
        d = fabs(x-xs);
        x = xs;
        xs = g(x);
    }
    return x;
}

int main() {
    freopen("in", "r", stdin);
    double a, b, x;
    scanf("%lf%lf%lf", &x, &a, &b);
    bool check = true;
    double x0 = No(&check, x, a, b);
    if (check == false)
        printf("Khong co nghiem trong doan [a, b]");
    else
        printf("Nghiem cua phuong trinh la: %.3lf ", x0);
    return 0;
}
