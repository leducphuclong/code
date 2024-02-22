// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdbool.h>

#define nln '\n'

// Declare global variables.

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int m = i, l = 2*i+1, r = 2*i+2;

    if (l < n && arr[l] > arr[m])
        m = l;

    if (r < n && arr[r] > arr[m])
        m = r;

    if (m != i) {
        swap(arr+i, arr+m);
        heapify(arr, n, m);
    }
}

void build_max_heapy_array(int arr[], int n) {
    for (int i = n/2-1; i >= 0; --i)
        heapify(arr, n, i);
}

bool is_kth_greater_than_x(int arr[], int n, int k, int x, int th, int *cnt) {
    if (th >= n || arr[th] <= x)
        return 0;
    ++*cnt;
    if (*cnt >= k)
        return 1;
    return is_kth_greater_than_x(arr, n, k, x, 2*th+1, cnt) ||
    is_kth_greater_than_x(arr, n, k, x, 2*th+2, cnt);
}

int main(int argc, char* argv[]) {
    // Input
    int arr[100000] = {0, 1, 2, 4, 3, 7, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 1, k = 6;
    scanf("%i%i%i", &n, &x, &k);
    for (int i = 0; i < n; ++i)
        scanf("%i", arr+i);
    // Solve
    // Build heap array
    build_max_heapy_array(arr, n);
    // printArray(arr, n);
    // Check
    int cnt = 0;
    bool check = is_kth_greater_than_x(arr, n, k, x, 0, &cnt);
    if (check)
        // printf("Yes\n");
        printf("Yes, the k'th largest number is greater than x.\n");
    else
        // printf("No\n");
        printf("No, the k'  th largest number is not greater than x.\n");
    return 0;
}
