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

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%i ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_heapify(int arr[], int n, int index) {
    int left = index*2+1, right = index*2+2;
    int largest = index;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != index) {
        swap(arr+largest, arr+index);
        max_heapify(arr, n, largest);
    }
}       

void build_max_heap(int arr[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        max_heapify(arr, n, i);
}

void heapsort(int arr[], int n) {
    for (int i = n-1; i >= 0; i--) {
        swap(arr, arr+i);
        max_heapify(arr, i, 0);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {1, 4, 3, 31, 432, 432, 423, 1313, 121, 12, 13, 432};
    int n = sizeof(arr)/sizeof(int);
    printf("Original array: ");
    print_array(arr, n);
    build_max_heap(arr, n);
    heapsort(arr, n);
    printf("Heapsorted array: ");
    print_array(arr, n);
    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
