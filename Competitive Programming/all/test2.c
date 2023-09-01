#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double c[100][100], d[100][100];
void docfile(double a[][100], int *n){
    FILE *inp;
	char *tenfile;
	do{
	printf ("Nhap ten file input da luu san: ");
	//scanf ("%s", tenfile);
	tenfile = "in";
	inp = fopen(tenfile,"r");
    if(inp==NULL){
        printf("File khong ton tai! Moi nhap lai!\n");
    	}
	}while(inp==NULL);
	fscanf(inp,"%d",n);
    for(int i=0; i<*n; i++){
        for(int j=0; j<*n; j++){
            if (!feof(inp))
				fscanf(inp,"%lf",&a[i][j]);
			else {
				printf ("Du lieu khong hop le!");
				return;
			}	
        }
        fscanf(inp,"\n");
    }
    fclose(inp);
}

void xuat(double a[][100], int n){
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%lf\t",a[i][j]);
        }
        printf("\n");
    }
}

void xuli(double a[][100], double b[][100], int n){
	for (int i=0;i<n;i++){//ham tinh tong
		for(int j=0; j<n;j++){
			d[i][j]= a[i][j]+b[i][j];
		}
	}
	for (int i=0; i<n;i++){// ham tinh tich
		for (int j=0; j<n;j++){
			c[i][j]=0;
			for(int k=0; k<n;k++){
				c[i][j] += a[i][k] * b[k][j];
		}
	}
}
}

void ghifile(int n){
    FILE *oup;
    oup = fopen("out","w");
    fprintf (oup,"Ma tran tich:\n");
    fprintf (oup, "%d\n", n);
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           	fprintf(oup,"%lf\t",c[i][j]);
        }
        fprintf(oup,"\n");
    }
    fprintf (oup,"Ma tran tong:\n");
    fprintf (oup, "%d\n", n);
	for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           	fprintf(oup,"%lf\t",d[i][j]);
        }
        fprintf(oup,"\n");
    }
    fclose(oup);
}

int main(){        
    double a[100][100], b[100][100];
    int n,m;
	docfile(a,&n);
		printf ("Ma tran A:\n");
    xuat(a,n);
    docfile(b,&m);
    printf ("Ma tran B:\n");
    xuat(b,m);
	xuli(a,b,n);
	printf ("Ma tran tich:\n");
	xuat(c,n);
	printf ("Ma tran tong:\n");
	xuat(d,n);
	ghifile(n);
}