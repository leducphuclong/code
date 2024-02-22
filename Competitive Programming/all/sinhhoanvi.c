#include<stdio.h>
#include<conio.h>

const int N = 100;

int cnt = 0; char b[N] = " abcd";

void print(int n,int a[N]){
    ++cnt;
    for (int i = 1; i <= n; ++i)
        printf("%c ", b[a[i]]);
    printf("%c", '\n');
}

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

void reverse(int l, int r, int a[N]){
    while (l < r){
        swap(a[l], a[r]);
        ++l; --r;
    }
}

bool generate(int n, int a[N]) {
    int i = n-1;
    while (i >= 1 && a[i] > a[i+1])
        i--;
    if (i == 0)
        return false;        
    // Vi tri i can thay doi
    // Gio tim j la vi tri nho nhat
    // lon hon so thu i
    // Day phia sau i la day giam dan
    // So dau tien la so nho nhat > i
    int j = n;
    while (j > i && a[j] < a[i])
        --j;
    // Tim duoc j la so can tim
    // Doi cho ai va aj
    swap(a[i], a[j]);
    // ta da tim duoc so dung thu i
    // va day giam dan phia sau i
    // dao nguoc lai day giam dan do
    // return;
    reverse(i+1, n, a);
    return true;
}

int main(){
    int n = 4;
    // scanf("%d", &n);
    int a[N];
    // Khoi tao hoan vi dau tien
    for (int i = 1; i < n+1; ++i)
        a[i] = i;
    print(n, a);
    while (generate(n, a) == true){
        print(n, a);
    }
    printf("so luong: %i", cnt); 
    return 0;

}