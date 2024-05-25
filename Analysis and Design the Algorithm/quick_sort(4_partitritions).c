// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <conio.h>

typedef struct {
    int first, second;
} intPair;

void view(int *arr, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", *(arr+i));
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}   

intPair partition(int *arr, int l, int r) {
    // choose the last element in the segment arr[r] as a pivot
    
    /* // When in looping
    A[p...q-1] < pivot
    A[q...t] = pivot
    A[t+1, i-1] > pivot
    A[i, r] = undefined */

    // choose arr[r] as pivot

    int q = l, t = l-1, i = l-1;
    while (i < r-1) {
        i++;
        if (arr[i] < arr[r]) {
            swap(arr + t + 1, arr + i); // arr[i] at t+1
            swap(arr + t + 1, arr + q); // arr[i] at q
            t++, q++;
        } else if (arr[i] == arr[r]) {
            swap(arr + t + 1, arr + i); // arr[i] at t+1;
            t++;
        }
    }
    swap(arr + r, arr + t + 1);
    t++;
    intPair result = {q, t};
    return result;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        intPair loc = partition(arr, l, r);
        // this part contains elements which less than or equal to arr[q]
        quickSort(arr, l, loc.first - 1); 
        // this part contains elements which greater than arr[q]
        quickSort(arr, loc.second + 1, r);
    }
}


int main(int argc, char const *argv[]) {
    // Opening input file
    if (access("in", F_OK) != -1) {
        FILE *file = freopen("in", "r", stdin);
        if (file == NULL) {
            perror("Error opening file!");
            return 1;
        }
    }

    // Load the input data
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed!");
        return 1;
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    // Sort
    quickSort(arr, 0, n-1);

    // View the result
    view(arr, n);

    return 0;
}
