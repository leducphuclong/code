#include <stdio.h>

int arr[4], pos[4], exist[int(1e5)];
bool used[4];

void recurse(int idx) {
    if (idx == 4) {
        int n = 0;
        for (int i = 0; i < 4; ++i)
            n *= 10, n += arr[pos[i]];
        exist[n] = true;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (!used[i]) {
            used[i] = true;
            pos[idx] = i;
            recurse(idx+1);
            used[i] = false;
        }
    }
}

int main() {
    printf("Enter those 4 numbers: ");
    for (int i = 0; i < 4; ++i)
        scanf("%i", arr+i);

    recurse(0);

    printf("2 - 2: \n");
    for (int i = 0; i <= 9999; ++i) {
        if (exist[i]) {
            int left = i / 100, right = i % 100;
            if (left < 10 || right % 10 == 0)
                continue;
            printf("%i.", left);
            if (right < 10)
                printf("0");
            printf("%i\n", right);
        }
    }

    printf("3 - 1: \n");
    for (int i = 0; i <= 9999; ++i) {
        if (exist[i]) {
            int left = i / 10, right = i % 10;
            if (left > 99) {
                printf("%i.%i\n", left, right);
            }
        }
    }    

    printf("1 - 3: \n");
    for (int i = 0; i <= 9999; ++i) {
        if (exist[i]) {
            int left = i / 1000, right = i % 1000;
            if (right % 10 == 0)
                continue;
            printf("%i.", left);
            if (right < 10)
                printf("00");
            else if (right < 100)
                printf("0");
            printf("%i\n", right);
        }
    } 

    return 0;
}