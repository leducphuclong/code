// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

/* Some math theory:
    Quantity: 5A3 = n!/(n-k)!
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
bool pick[N];
int cnt = 0;
// End of global variable declaration.

void recurse(int arr[], int n, int i) {
    if (i == n) {
        ++cnt;
        for (int j = 0; j < n; j++)
            printf("%i ", arr[j]);
        printf("\n");
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (!pick[j]) {
            arr[i] = j;
            pick[j] = 1;
            recurse(arr, n, i+1);
            pick[j] = 0;
        }
    }
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%i", &n);
    int arr[n+1];
    memset(pick, 0, sizeof(bool)*(n+1));
    recurse(arr, n, 0);
    printf("Quantity: %i", cnt);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
