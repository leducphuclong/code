#include<stdio.h>

const int N = 100;

void swap(int *a, int *b) {
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

void view(int a[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
    printf("\n");
}

void max_heapify(int a[], int k, int n) {
    // Tim nut con
    int l = 2*k+1, r = 2*k+2;
    int max_node = k;
    if (l < n && a[l] > a[k] && a[l] > a[r])
        max_node = l;
    if (r < n && a[r] > a[k] && a[r] > a[l])
        max_node = r;
    if (max_node != k) {
        swap(a+k, a+max_node);
        max_heapify(a, max_node, n);
    }
}

void build_heap_tree(int a[], int n) {
    for (int i = (n-3)/2+1; i >= 0; --i)
        max_heapify(a, i, n);
}

void heapsort(int a[], int n) {
    while (n > 0) {
        if (n > 2)
            swap(a, a+n-1);
        n--;
        max_heapify(a, 0, n);
    }
}

int main() {
    int n = 11;
    int a[N] =  {17,8,1,5,7,3,4,10,15,6,9};
    view(a, n);
    build_heap_tree(a, n);
    printf("after build heap tree: \n");
    view(a, n);
    heapsort(a, n);
    printf("after heap sort: \n");
    view(a, n);
    return 0;
}
