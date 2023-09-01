#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>

const double eps = 1e-4;

double f(double x) {
    return pow(x, 3) + x - 5;
}

double fdh(double x) {
    return 3*pow(x, 2) + 1;
}

double No(bool *check, double x) {
    double y = x, d = 100000;
    while (fabs(y-x) < d && fabs(y-x) >= eps) {
        y = x;
        d = fabs(y-x);
        x = y-f(y)/fdh(y);
    }
    if (fabs(xs-x) >= d)
        return false;
    return x;
}

int main() {
    // freopen("in", "r", stdin);
    double a, b, x;
    scanf("%lf", &x);
    bool check = true;
    double x0 = No(&check, x);
    if (check == false)
        printf("Phuong tring co nghiem khong hoi tu");
    else
        printf("Nghiem cua phuong trinh la: %.3lf ", x0);
    return 0;
}
