// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/* Some math theory:
    Quantity: (n+r-1)C(r)
    - Imagine more (r-1) dump elements.
*/

// Include
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
int cnt = 0;
// End of global variable declaration.

void recurse(int arr[], int n, int k, int i) {
    if (i == k+1) {
        ++cnt;
        for (int j = 1; j <= k; j++)
            printf("%i ", arr[j]);
        printf("\n");
        return;
    }
    for (int j = arr[i-1]+1; j <= n; ++j) {
        arr[i] = j;
        recurse(arr, n, k, i+1);
    }
}

int main(int argc, char* argv[]) {
    int n, k;
    scanf("%i%i", &n, &k);
    int arr[N];
    arr[0] = 0;
    recurse(arr, n, k, 1);
    printf("Quantity: %i", cnt);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
