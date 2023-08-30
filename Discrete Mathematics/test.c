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
bool stop = 0;
int arr[N], cnt = 0;
// End of global variable declaration.

void print(bool b[], int n) {
    printf("Tap con thu %i la: ", ++cnt);
    for (int i = 0; i < n; ++i)
        if (b[i])
            printf("%i ", arr[i]);
    printf("\n");
}

bool is_stop(bool b[], int n) {
    int i = n;
    while (--i >= 0 && b[i] == 1)
        continue;
    if (i < 0)
        return true;
    b[i] = 1;
    for (int j = i+1; j < n; ++j)
        b[j] = 0;
    return false;
}
  
void generate(int n) {
    bool b[N];
    int cnt = 0;
    while (!stop) {
        print(b, n);
        stop = is_stop(b, n);
        ++cnt;
    }
    printf("quality: %i\n", cnt);
}

int main(int argc, char* argv[]) {
 
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        arr[i] = i+1;
    generate(n);
    fprintf(stderr, "\n%s\n", "It's ok Long, Good for now !!");
    return 0;
}
