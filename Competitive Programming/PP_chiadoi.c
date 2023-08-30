#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

const double eps = 1e-5;

double f(double x) {
    return pow(2, x)+x-4;
}

double No(bool *check, double a, double b) {
    if (f(a)*f(b) >= 0) {
        *check = false;
        return -1;
    }
    double c = (a+b)/2;
    printf("%lf ", eps);
    while (f(c) != 0 && fabs(a-b) > eps) {
        c = (double)(a+b)/2.0;
        if (f(a)*f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    bool check = true;
    double x0 = No(&check, a, b);
    if (check == false)
        printf("Khong co nghiem trong doan [a, b]");
    else
        printf("Nghiem cua phuong trinh la %lf: ", x0);
    return 0;
}
