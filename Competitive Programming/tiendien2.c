#include<stdio.h>

int main()
{
	//FILE *f1, *f2;
	//f1 = freopen("tiendien.inp", "r", stdin);
	//f2 = freopen("tiendien.out", "w", stdout);
	int fi, la;
	printf("Nhap chi so dien dau ky: ");
	scanf("%d", &fi);
	printf("Nhap chi so dien cuoi ky: ");
	scanf("%d", &la);
	int kw = la-fi;
	printf("%d", (bool)(kw / 100)*(kw - 100)*2000 + (kw*(bool)!(kw-100) + kw*(bool)!(kw/100) + 100*(bool)((kw / 100)*(kw - 100)))*1000);
	//fclose(f1);
	//fclose(f2);
	return 0;
}