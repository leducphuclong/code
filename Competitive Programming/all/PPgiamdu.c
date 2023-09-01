// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <stdio.h>

#define nln '\n'

const int N = 100;

// Declare global variables.
int a[100][100], n, v[100];

void get_data() {
    int n;
    scanf("%i", &n);
    for (int i = 1 ; i <= n; ++i) {
        printf("Hi");
        for (int j = 1; j <= n; ++j) {
            scanf("%i", a(i)(j));
        }
        printf(nln);
    }

}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    get_data();
    return 0;
}
