#include<stdio.h>

void view(int n, int a[]) {
    for (int i = 0; i <= n; ++i)
        printf("%i ", a[i]);
    printf("%c", '\n');
}

int Hoocner(int n, int a[], int c) {
    int p[n+1];
    p[0] = a[0];
    for (int i = 1; i <= n; ++i)
        p[i] = p[i-1]*c+a[i];
    return p[n];
}

int main() {
    freopen("in", "r", stdin);
    // printf("Nhap bac phuong trinh: " );
    int n, a[n+1];
    scanf("%i", &n);
    for (int i = 0; i <= n; ++i){
        // printf("Nhap A %i :", i);
        scanf("%i", &a[i]);
    }
    // p-rintf("Nhap c: ");
    int c;
    scanf("%i", &c);
    printf("%i", Hoocner(n, a, c));
    return 0;
}