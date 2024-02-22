#include <iostream>

using namespace std;

void show(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool ascending(int a, int b) {
    return a > b;
}

bool decrease(int a, int b) {
    return a < b;
}

void sort(int *arr, int n, bool (*cmp)(int, int) = ascending) {
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (cmp(*(arr+i), *(arr+j)))
                swap(arr+i, arr+j);
}

int main() {
    int arr[] = {1, 2, 4, 2, 0, -1, 3, -4};
    int n = sizeof(arr) / sizeof(int);
    sort(arr, n);
    show(arr, n);
    return 0;
}