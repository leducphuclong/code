#include <stdio.h>
#include <limits.h>
#include <conio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int index_min_of(int* a, int s, int n) {
	int MIN = INT_MAX, loc = -1;
	for (int i = s; i < n; ++i)
		if (a[i] < MIN)
			MIN = a[i], loc = i;
	return loc;
}

void push(int v, int idx, int* arr, int* n) {
	for (int i = *n; i > idx; --i)
		arr[i] = arr[i-1];
	arr[idx] = v;
	(*n)++;
}

void print(int* arr, int n) {
	for (int i = 0; i < n; ++i)
		printf("%i ", arr[i]);
	printf("\n");
}

int main() {
	// freopen("in", "r", stdin);

	int n, m;	scanf("%i%i", &n, &m);
	int a[n], b[m+n];
	for (int i = 0; i < n; ++i)
		scanf("%i", a+i);
	for (int i = 0; i < m; ++i)
		scanf("%i", b+i);
	for (int i = m; i < n+m; ++i)
		b[i] = INT_MAX;

	printf("Array 1:\n");
	print(a, n);

	printf("Array 2:\n");
	print(b, m);
	printf("\n");

	int i = 0;
	while (true) {
		// print(a, n);
		// print(b, m);
		int ia = index_min_of(a, 0, n),
		    ib = index_min_of(b, i, m);
		// printf("ia: %i\n", ia);
		// printf("ib: %i\n", ib);
		if (ia == -1)
			break;
		if (a[ia] < b[ib]) {
			push(a[ia], i, b, &m);
			a[ia] = INT_MAX;
		} else {
			swap(b+i, b+ib);
		}
		i++;
		// print(a, n);
		// print(b, m);
		// printf("\n");
		// getch();
	}

	printf("Result Array: \n");
	print(b, m);

	return 0;
}