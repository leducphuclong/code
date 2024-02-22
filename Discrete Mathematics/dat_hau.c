// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
bool md[N], ad[N], col[N];
int n, pos_row[N], cnt = 0;
// End of global variable declaration.

bool check(int r, int c) {
    return !col[c] && !md[r-c] && !ad[r+c];
}

void recurse(int r) {
    if (r > n) {
        ++cnt;
        return;
    }
    for (int c = 1; c <= n; ++c)
        if (check(r, c)) {
            pos_row[r] = c;
            col[c] = md[r-c] = ad[r+c] = true;
            recurse(r+1);
            col[c] = md[r-c] = ad[r+c] = false;
        }
}

int main(int argc, char* argv[]) {
    scanf("%i", &n);
    recurse(1);
    printf("Answer: %i\n", cnt);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
