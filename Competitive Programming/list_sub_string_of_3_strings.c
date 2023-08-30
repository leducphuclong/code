#include<stdio.h>
#include<string.h>

char x[3][100] = {"abc", "de", "mnt"};
FILE *fi, *fo;

void recurse(int i, char res[100])
{
	if (i == 3){
		fprintf(fo, "%s \n", res);
		return;
	}
	for (int j = 0; j < strlen(x[i]); ++j){
		strncat(res, &x[i][j], 1);
		recurse(i+1, res);
		res[strlen(res)-1] = '\0';
	}
}

int main()
{
	fi = fopen("in", "r");
	fclose(fi);

	fo = fopen("out", "w");
	char res[100] = "";
	recurse(0, res);
	fclose(fo);
	return 0;
}
// NOLINTEND