// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

int main(int argc, char* argv[]) {
    // Initialize data
    int arr[] = {4, 1, 2, 2, 3};
    int n = sizeof(arr)/sizeof(int); // no elements
    int cnt[5]; memset(cnt, 0, sizeof(int)*5);
    // Counting
    for (int i = 0; i < n; ++i)
        cnt[arr[i]]++;
    // Build prefix sum
    for (int i = 1; i < 5; ++i)
        cnt[i] += cnt[i-1];
    // Output the result
    int res[n];
    for (int i = 0; i < n; ++i)
        res[cnt[arr[i]]-1] = arr[i], cnt[arr[i]]--;
    for (int i = 0; i < n; ++i)
        printf("%i ", res[i]);
    printf("\n");
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
