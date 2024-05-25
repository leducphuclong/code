#include <stdio.h>

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to view the array
void view(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Partition function as provided
int partition(int* arr, int l, int r) {
    int i = l - 1, j = l - 1;

    // Iterate over the array and partition it
    while (j < r - 1) {
        j++;
        if (arr[j] <= arr[r]) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);

    // printf("%d %d %d \n", l, i + 1, r);
    // view(arr, r - l + 1);

    return i + 1;
}

// QuickSort function
void quicksort(int* arr, int l, int r) {
    if (l < r) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, l, r);

        // Recursively sort the subarrays
        quicksort(arr, l, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, r);
    }
}

int main() {
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    view(arr, size);

    // Perform quicksort on the entire array
    quicksort(arr, 0, size - 1);

    printf("Sorted array:\n");
    view(arr, size);

    return 0;
}
