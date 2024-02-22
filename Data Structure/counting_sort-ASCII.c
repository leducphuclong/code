// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>
#include <string.h>

#define nln '\n'

// Declare global variables.

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    // Get the input data
    int n;
    scanf("%i", &n);
    char str[100];
    scanf("%s", &str);
    // Precompute Counting Sort
    int cnt[123];
    // Ascii code: a -> z:  97 -> 122
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; ++i)
        cnt[(int)(str[i])]++
        
    for (int i = 97; i <= 122; ++i)
        cnt[i-96] = cnt[i]+cnt[i-97];

    char res[100];
    for (int i = 0; i < n; ++i) {
        res[cnt[(int)(str[i])-96]] = str[i];
        cnt[(int)(str[i])-96]--;
    }
    for (int i = 1; i <= n; ++i)
        printf("%c", res[i]);

    return 0;
}
