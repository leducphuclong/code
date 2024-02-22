// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <stdio.h>
#include <string.h>
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct

// Constant

// Declare global variables.
// End of global variable declaration.

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%i%i", &n, &m);
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(int)*(m+1)*(n+1));
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] += dp[i-1][j]+dp[i][j-1];
    printf("%i\n", dp[n][m]);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
