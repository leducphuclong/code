// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <limits.h>

#define nln '\n'

// Declare global variables.

int max_array(int a[], int n) {
    int mav = INT_MIN;
    for (int i = 0; i < n; ++i)
        if (a[i] > mav)
            mav = a[i];
    return mav;
}

int main(int argc, char* argv[]) {
    // Data
    int a[] = {1, 1, 3, 3, 2, 5};
    int n = sizeof(a)/sizeof(a[0]);
    // Build the counting array
    int k = max_array(a, n);
    int c[k+1] = {0};
    for (int i = 0; i < n; ++i)
        ++c[a[i]];
    // Build the prefix sum counting array
    for (int i = 1; i <= k; ++i)
        c[i] += c[i-1];
    // Print
    int b[n] = {0};
    for (int i = 0; i < n; ++i) {
        b[c[a[i]]-1] = a[i];
        c[a[i]]--
    }
    // Output
    printf("After counting sort: \n");
    for (int i = 0; i < n; ++i)
        printf("%i ", b[i]);
    printf("\n");
    return 0;
}
