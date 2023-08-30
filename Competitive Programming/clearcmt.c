#include<stdio.h>
#include<conio.h>
#include<string.h>

#define long long long
#define nln '\n'

int main()
{
	freopen("input.c", "r", stdin);
	
	size_t size;
	char * buf=NULL;
	while(getline(&buf,&size,stdin)!=EOF){
        puts(buf); 
	}
	return 0;
}
