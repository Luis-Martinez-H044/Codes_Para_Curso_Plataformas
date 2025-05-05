#include <stdio.h>

#define N 3

int main() {
    int matriz[N][N] = {
        {4, 2, 6},
        {18, 15, 2},
        {9, 8, 10}
    };

    int suma[2 * N - 1];
    int suma2[2 * N - 1]; 

    
    for (int i = 0; i < 2 * N - 1; i++) {
        suma[i] = 0;
        suma2[i] = 0;
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            suma[i - j + (N - 1)] += matriz[i][j];
        }
    }

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            suma2[i + j] += matriz[i][j];
        }
    }

    
    printf("Diagonales (i - j):\n");
    for (int i = 0; i < 2 * N - 1; i++) {
        printf("Diagonal %d: %d\n", i + 1, suma[i]);
    }

    printf("\nDiagonales  (i + j): \n");
    for (int i = 0; i < 2 * N - 1; i++) {
        printf("Diagonal %d: %d\n", i + 1 + (2 * N - 1), suma2[i]);
    }

    return 0;
}