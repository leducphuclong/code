// Le Duc Phuc Long, 2024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int ll;

void view(ll *arr, ll n) {
	for (ll i = 0; i < n; ++i)
		printf("%d ", *(arr+i));
	printf("\n");
}

void swap(ll *a, ll *b) {
	ll temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(ll *arr, ll heapSize, ll index) {
	ll largest = index;

	if (index*2 + 1 < heapSize && arr[index*2 + 1] > arr[largest])
		largest = index*2 + 1;
	if (index*2 + 2 < heapSize && arr[index*2 + 2] > arr[largest])
		largest = index*2 + 2;

	if (largest != index) {
		swap(arr + index, arr + largest);
		maxHeapify(arr, heapSize, largest);
	}
}

void buildMaxHeap(ll *arr, ll n) {
	for (ll i = n/2; i >= 0; --i)
		maxHeapify(arr, n, i);
}

void heapSort(ll *arr, ll n) {
	ll heapSize = n;
	for (ll i = n-1; i >= 0; --i) {
		swap(arr + 0, arr + i);
		heapSize -= 1;
		maxHeapify(arr, heapSize, 0);
	}
}

int main(int argc, char const *argv[])
{
	// Open input file
	if (access("in", F_OK) != -1) {
		FILE *file = freopen("in", "r", stdin);
		if (file == NULL) {
			perror("Error opening file");
			return 1;
		}
	}

	// Load the input date
	ll n;	scanf("%d", &n);
	ll *arr = (ll *)malloc(n*sizeof(ll));
	if (arr == NULL) {
		perror("Memory allocation failed\n");
		return 1;
	}

	for (ll i = 0; i < n; ++i)
		scanf("%d", arr+i);

	// Build Max Heap
	buildMaxHeap(arr, n);
	heapSort(arr, n);

	// View the result
	view(arr, n);

	free(arr);

	return 0;
}