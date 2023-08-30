#include<stdio.h>
#include<math.h>

const double e = 2.71828, eps = 1e-4;

double f(double x){
	return pow(e, x)-10*x+7;
}

double f1(double x){
	return pow(e, x)-10;
}

int main()
{
	double x0;
	scanf("%lf", &x0);
	
	double d = 1000000;
	while (1){
		double x = x0-f(x0)/f1(x0);
		// printf("%lf\n", x);
		if (abs(x-x0) <= eps || abs(x-x0) > d){
			if (abs(x-x0) > d)
				d = -1;
			break;
		}
		d = abs(x-x0);
		x0 = x;
	}
	if (d == -1){
		printf("Không hội tụ");
	}
	else
		printf("nghiem : %lf", x0);

	return 0;
}