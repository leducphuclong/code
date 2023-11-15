#include <stdio.h>

int main() {
    long long n;
    printf("n? : ");
    scanf("%lli", &n);
    long long ans = 0, tmp = 1;
    while (tmp < n/5) {
        tmp *= 5,
        ans += n/tmp;
    }
    printf("result: %lli\n", ans);
    return 0;
}