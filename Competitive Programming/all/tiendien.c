#include<stdio.h>

int main() {
	//FILE *f1, *f2;
	//f1 = freopen("tiendien.inp", "r", stdin);
	//f2 = freopen("tiendien.ans", "w", stdout);
	int fi, la;
	printf("Nhap chi so dien dau ky: ");
	scanf("%d", &fi);
	printf("Nhap chi so dien cuoi ky: ");
	scanf("%d", &la);
	int kw = la-fi;
	if (kw > 100)
		printf("%d", 100*1000+(kw-100)*2000);
	else
		printf("%d", kw*1000);
	//fclose(f1);
	//fclose(f2);
	return 0;
}
