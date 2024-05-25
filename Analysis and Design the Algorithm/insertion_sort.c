// Le Duc Phuc Long, 2024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int ll;

void view(ll arr[], ll n) {
	for (ll i = 0; i < n; ++i)
		printf("%d ", *(arr+i));
	printf("\n");
}

void insertion_sort(ll arr[], ll n) {
	for (ll i = 1; i < n; ++i) {
		ll key = arr[i];
		ll j = i;
		while (j > 0 && key < arr[j-1]) {
			arr[j] = arr[j-1];
			j -= 1;
		}
		arr[j] = key;
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

	ll n;	scanf("%d", &n);
	ll *arr = (ll *)malloc(n*sizeof(ll));
	if (arr == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}
	for (ll i = 0; i < n; ++i)
		scanf("%d", arr+i);

	insertion_sort(arr, n);

	view(arr, n);

	free(arr);

	return 0;
}