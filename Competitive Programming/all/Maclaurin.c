#include<stdio.h>
#include<math.h>

const double eps = 1e-10;
const double M_PI = 3.14159265359;

double sin_t(double x) {
    int fact = 1;
    double res = 0, l = x;
    while (fabs(l) >= eps) {
        res += l;
        l = -l*x*x/(double)((fact+1)*(fact+2));
        fact += 2;
    }
    return res;
}

int main() {
    double angle = 421;
    angle *= M_PI/180;
    printf("%lf\n", sin(angle));
    printf("%lf\n", sin_t(angle));
    return 0;
}