#include<stdio.h>

int main()
{
	printf("Nhap so luong: " );
	int so_luong;
	scanf("%d", &so_luong);
	printf("Nhap don gia: " );
	int don_gia;
	scanf("%d", &don_gia);
	int tien = so_luong*don_gia;
	printf("so tien phai tra: ");
	if (so_luong <= 50)
		printf("%d", tien);
	else
		printf("%f", (double)tien*95/100);
	return 0;
}