#include<stdio.h>

#define long long long
#define nln '\n'
typedef int aaa[3];

int main()
{
	aaa a;
	a[2] = 10; 
	printf("%d", a[2], "%c", '\n');
	char str[3];
	gets(str);
	char pl1 = str[0], pl2 = str[2];
	if (pl1 == 'B'){
		if (pl2 == 'K')
			printf("WIN");
		else
			if (pl2 == 'G')
				printf("LOSE");
			else
				printf("DRAW");
	}
	if (pl1 == 'K'){
		if (pl2 == 'G')
			printf("WIN");
		else
			if (pl2 == 'B')
				printf("LOSE");
			else
				printf("DRAW");
	}
	if (pl1 == 'G'){
		if (pl2 == 'B')
			printf("WIN");
		else
			if (pl2 == 'K')
				printf("LOSE");
			else
				printf("DRAW");
	}
	return 0;
}