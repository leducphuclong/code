// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

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

int partition(int *arr, int l, int r) {
    // choose the last element in the segment arr[r] as a pivot

    int i = l-1, j = l-1;
    // We will devide the segment l --> r into 3 parts:
    // l -> i : contains elements <= pivot.
    // i + 1 -> j : contains elements > pivot.
    // j + 1 -> r : undefined elements.

    while (j < r-1) {
        j++;
        if (arr[j] <= arr[r]) {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + r);

    
    return i + 1;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int q = partition(arr, l, r);
        // this part contains elements which less than or equal to arr[q]
        quickSort(arr, l, q-1); 
        // this part contains elements which greater than arr[q]
        quickSort(arr, q+1, r);
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
