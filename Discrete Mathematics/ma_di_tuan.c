// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 10

// Typedef and Struct

// Constant

// Declare global variables.
int n;
int B[N][N];
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
// End of global variable declaration.

void output() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            printf("%i ", B[i][j]);
        printf("\n");
    }
}

bool check(int x, int y) {
    return (x > 0 && x <= n && y > 0 && y <= n && !B[x][y]);
}

void move(int x, int y, int step) {
    B[x][y] = step;
    for (int st = 0; st < 9; ++st) {
        if (step == n*n) {
            output();
            exit(0);
        }
        if (st > 7)
            continue;
        int n_x = x + X[st], n_y = y + Y[st];
        if (check(n_x, n_y))
            move(n_x, n_y, step+1);
    }
    B[x][y] = 0;
}

int main(int argc, char* argv[]) {
    printf("Enter the size of the board: ");
    scanf("%i", &n);
    printf("Enter the original coordinates: ");
    int x, y;
    scanf("%i%i", &x, &y);
    move(x, y, 1);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
