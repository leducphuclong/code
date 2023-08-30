#include<stdio.h>

int main() {
	int fi, la;
	printf("Nhap so dien dau ky: ");
	scanf("%d", &fi);
	printf("Nhap so dien cuoi ky: ");
	scanf("%la", &la);
	int kw = la-fi;
	if (kw > 100)
		printf("%d", 100*1000+(kw-100)*2000);
	else
		printf("%d", kw*1000);
	return 0;
}
