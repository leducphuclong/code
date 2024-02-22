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
// End Declare global variables

void print_configure(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%i ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(int arr[], int left, int right) {
    for (int i = left; i < left+(right-left+1)/2; ++i)
        swap(&arr[i], &arr[right-(i-left)]);
}

bool is_stop(int arr[], int n) {
    int i = n-1;
    while (--i >= 0 && arr[i] > arr[i+1])
        continue;
    if (i < 0)
        return true;
    int j = n;
    while (--j >= 0 && arr[j] < arr[i])
        continue;
    swap(arr+i, arr+j);
    reverse(arr, i+1, n-1);
    return false;
}

void generate(int n) {
    int cnt = 0;
    int arr[N];
    for (int i = 0; i < n; ++i)
        arr[i] = i+1;
    bool stop = 0;
    while (!stop) {
        print_configure(arr, n);
        stop = is_stop(arr, n);
        ++cnt;
    }
    printf("Quality: %i\n", cnt);
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%i", &n);
    generate(n);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
