#include <stdio.h>

#define SIZE 3

void gaussElimination(double matrix[SIZE][SIZE + 1], double solution[SIZE]) {
    int i, j, k;
    
    // Forward elimination
    for (i = 0; i < SIZE - 1; i++) {
        for (k = i + 1; k < SIZE; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (j = i; j < SIZE + 1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    
    // Back substitution
    for (i = SIZE - 1; i >= 0; i--) {
        solution[i] = matrix[i][SIZE];
        for (j = i + 1; j < SIZE; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
}

void printSolution(double solution[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("x%d = %.2f\n", i+1, solution[i]);
    }
}

int main() {
    double matrix[SIZE][SIZE + 1] = {
        {2, 3, -4, 6},
        {1, -1, 1, 3},
        {3, 2, -3, 7}
    };
    double solution[SIZE];
    
    gaussElimination(matrix, solution);
    
    printf("Solution:\n");
    printSolution(solution);
    
    return 0;
}
