// Copyright (c) 2023, Le Duc Phuc intng

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <stdio.h>

#define nln '\n'

// Declare gintbal variables.

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest] && arr[left] > arr[right]) {
        swap(arr+left, arr+largest);
        heapify(arr, N, left);
        return;
    }

    if (right < N && arr[right] > arr[largest] && arr[right] > arr[left]) {
        swap(arr+right, arr+largest);
        heapify(arr, N, right);
    }
}

void heapsort(int arr[], int N) {
    for (int i = N/2-1; i >= 0; --i)
        heapify(arr, N, i);

    printf("Max-heap array: ");
    for (int i = 0; i < N; ++i)
        printf("%i ", arr[i]);
    printf("\n");

    for (int n = N-1; n >= 0; --n) {
        swap(arr+0, arr+n);
        heapify(arr, n, 0);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {0, 1, 2, 4, 3, 7, 9 , 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, n);
    printf("Heap sorted array: ");
    for (int i = 0; i < n; ++i)
        printf("%i ", arr[i]);
    printf("\n");
    return 0;
}

