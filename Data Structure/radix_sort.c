// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <limits.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

void print(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%i ", arr[i]);
    printf("\n");
}

void counting_sort(int arr[], int n, int e, int base) {
    // Initial bucket
    int bucket[base];
    for (int i = 0; i < base; ++i)
        bucket[i] = 0;
    // Counting
    for (int i = 0; i < n; ++i)
        bucket[arr[i]/e%base]++;
    // Position
    for (int i = 1; i < base; ++i)
        bucket[i] += bucket[i-1];
    // Sort
    int out[n];
    for (int i = n-1; i >= 0; --i)
        out[--bucket[arr[i]/e%base]] = arr[i];
    // Result
    for (int i = 0; i < n; ++i)
        arr[i] = out[i];
}

void radix_sort(int arr[], int n) {
    int m_e = INT_MIN;
    for (int i = 0; i < n; ++i)
        if (arr[i] > m_e)
            m_e = arr[i];
    for (int e = 1; e <= m_e; e *= 10)
        counting_sort(arr, n, e, 10);
}

int main(int argc, char* argv[]) {
    // Initialize data
    int arr[] = {4, 1, 2, 2, 3, 321, 1, 432, 231, 2, 312, 1, 143, 4, 521, 321, 5432, 24};
    int n = sizeof(arr)/sizeof(int);  // no elements
    printf("Original array: ");
    print(arr, n);
    radix_sort(arr, n);
    printf("Radix sorted array: ");
    print(arr, n);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
