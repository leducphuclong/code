#include<stdio.h>
#include<conio.h>

#define M 20
int main(){
	int i,j,n,m,f,a[M],b[M],c[M];
	printf("nhap n=");
	scanf("%d",&n);
    printf("nhap m=");
	scanf("%d",&m);
	 for(int i=0;i<n;i++){
	 	printf("a%d=",i);
	 	scanf("%d",a+i);
	}
	for(int i=0;i<m;i++){
	 	printf("b%d=",i);
	 	scanf("%d",b+i);
    }
    i=0;j=0;f=0;
    while(i<n&&j<m){
    	if(a[i]>b[j]){
    		c[f]=a[i];
			i++;
		}
		else  {
			c[f]=b[j];
			j++;
		}
		f++;
	}
	while(i<n){
		c[f]=a[i];
		i++;
		f++;
	}
	while(j<m){
		c[f]=b[j];
		j++;
		f++;
	}
	for(i=0;i<f;i++){
		printf("%d ",c[i]);
	}
	return 0;
}