// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <stdbool.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 100

// Typedef and Struct

// Constant

// Declare global variables.
bool b[N];
int cnt = 0, n;
// End of global variable declaration.

void generate(int n, int i) {  // recursive function
    if (i == n) {  // base case
        ++cnt;
        for (int j = 0; j < n; ++j)
            printf("%i ", b[j]);
        printf("\n");
        return;
    }
    b[i] = 0;
    //  i = 2, n = 3
    generate(n, i+1);  // i now equal to 3
    //  i come back, i = 2
    b[i] = 1;
    generate(n, i+1);
}

int main(int argc, char* argv[]) {
    scanf("%i", &n);
    generate(n, 0);
    printf("count: %i\n", cnt);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
