#include<stdio.h>

void view(int n, int a[]) {
    for (int i = 0; i <= n; ++i)
        printf("%i ", a[i]);
    printf("%c", '\n');
}

void Hoocner(int n, int a[], int b[], int c) {
    for (int k = n; k >= 1; --k) 
        for (int i = 1; i <= k; ++i) 
            a[i] = a[i-1]*c + a[i];
    for (int i = 0; i <= n; ++i)
        b[i] = a[i];
}

int main() {
    // Input
    freopen("in", "r", stdin);
    int n, c, a[n+1];
    scanf("%i%i", &n, &c);
    for (int i = 0; i <= n; ++i)
        scanf("%i", &a[i]);
    // Tinh Toan
    int b[n+1];
    Hoocner(n, a, b, c);
    view(n, b);
    return 0;
}