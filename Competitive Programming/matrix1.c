#include<stdio.h>
#include<stdlib.h>

FILE *fi, *fo;

void doc(double a[][100], int n)
{
	fscanf(fi, "%i", n);
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
				fscanf(fi,"%lf",a[i][j]);
        }
        fscanf(fi,"\n");
    }
}


int main()
{
	printf("Hi");
	fi = fopen("in", "r"); // mo file doc
	fo = fopen("out", "w"); // mo file ghi
	fprintf(fo, "HI");
	int n = 0, m;
	double c[100][100], d[100][100];		
	doc(c, n);
	for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
        	fprintf(fo, "%lf", c[i][j]);
        fprintf(fo, "%c", '\n');
    }
	fclose(fi);     // dong file fi
    fclose(fo);     // dong file fo
	return 0;
}