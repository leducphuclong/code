// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdbool.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

bool is_stop(int arr[], int n, int k) {  // gen
    // Check if this is the last configure
    bool check = 0;
    int loc = -1;  // save the location of the not max value
    for (int i = k-1; i >= 0; --i)
        if (arr[i] != n-k+i+1) {  // check the max
            check = 1;
            loc = i;
            break;
        }
    if (check == 0)
        return true;  // Stop cuz it is the max configure
    arr[loc]++;
    for (int i = loc+1; i < k; ++i)
        arr[i] = arr[i-1]+1;
    return false;
}

void generate(int n, int k) {
    int arr[N], cnt = 0;
    for (int i = 0; i < k; ++i)
        arr[i] = i+1;  // Initial first configure
    bool stop = 0;
    while (stop == false) {
        // Print current configure
        for (int i = 0; i < k; ++i)
            printf("%i ", arr[i]);
        printf("\n");
        ++cnt;
        // Generating
        stop = is_stop(arr, n, k);
    }
    printf("Quantity: %i\n", cnt);
}

int main(int argc, char* argv[]) {
    freopen("out", "w", stdout);
    int n, k;
    scanf("%i%i", &n, &k);
    generate(n, k);
    
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
