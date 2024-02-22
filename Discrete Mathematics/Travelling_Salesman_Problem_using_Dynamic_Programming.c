// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
// #include <conio.h>

// Define
#define nln '\n'
#define N 32
#define M (int)(1e8)

// Typedef and Struct

// Constant

// Declare global variables.
int dist[N][N], n, subsets[M], size_of_subsets = 0;
// End of global variable declaration.

void input() {
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%i", &dist[i][j]);
}

void setup() {
}

void Travelling_Salesman_Problem() {
    setup();
}

void generate(int x, int n, int m, int subsets[]) {   // cCm
    if (m == 0) {
        printf("%0n\n", m);
        return;
    }
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    input();  // Checked Input
    Travelling_Salesman_Problem();
    // Test space begin
    generate(0, n, n, subsets);
    // Test space end

    fprintf(stderr, "%s\n", "It's ok Long, Good for now !!");
    return 0;
}
