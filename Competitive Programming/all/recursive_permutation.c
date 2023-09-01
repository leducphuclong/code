#include<stdio.h>

int n, cnt = 0;
int b[100];
int vst[100];
FILE *fi, *fo;

void rc(int i){
  if (i > n) {
		++cnt;
		for (long j = 1; j <= n; ++j)
			fprintf(fo, "%i", b[j]);
		fprintf(fo, "%s", "\n");
		return;
	}
	for (long j = 1; j <= n; ++j)
		if (!vst[j]){
			vst[j] = 1;
			b[i]=j;
			rc(i+1);
			vst[j] = 0;
		}
}

int main()
{
	fi = fopen("in", "r");
	fscanf(fi,"%d", &n);
	fclose(fi);

	fo = fopen("out", "w");
	rc(1);
	fprintf(fo, "qtt: %i", cnt);
	fclose(fo);

	return 0;
}