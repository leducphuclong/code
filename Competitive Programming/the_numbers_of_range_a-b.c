// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <limits.h>

#define nln '\n'

// Declare global variables.

int max_element(int a[], int n) {
    int res = INT_MIN;
    for (int i = 0; i < n; ++i)
        if (a[i] > res)
            res = a[i];
    return res;
}

int main(int argc, char* argv[]) {
    // Input
    int arr[] = {3, 1, 3, 2, 4, 7, 5};
    int n = sizeof(arr)/sizeof(int);
    int k = max_element(arr, n);
    int cnt[k+1];
    for (int i = 0; i <= k; ++i)
        cnt[i] = 0;
    // Preprocesses
    for (int i = 0; i < n; ++i)
        cnt[arr[i]]++;
    for (int i = 1; i <= k; ++i)
        cnt[i] += cnt[i-1];
    // Return result in O(1)
    printf("Nhap a va b(cach nhau dau cach): ");
    int a, b;
    scanf("%i%i", &a, &b);
    printf("So luong so trong khoang [a, b]: %i\n", cnt[b]-cnt[a-1]);

    return 0;
}
