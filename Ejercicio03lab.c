#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 5

int dlarga(int matriz[T][T]) {
    int consecutivos_maximos = 0;


    for (int col = T - 1; col >= 0; col--) {
        int i = 0, j = col;
        int contador = 0;
        while (i < T && j >= 0) {
            if (matriz[i][j] == 1)
                contador++;
            else
                contador = 0;
            if (contador > consecutivos_maximos)
                consecutivos_maximos = contador;
            i++;
            j--;
        }
    }


    for (int fila = 1; fila < T; fila++) {
        int i = fila, j = T - 1;
        int contador = 0;
        while (i < T && j >= 0) {
            if (matriz[i][j] == 1)
                contador++;
            else
                contador = 0;
            if (contador > consecutivos_maximos)
                consecutivos_maximos = contador;
            i++;
            j--;
        }
    }

    return consecutivos_maximos;
}

int main() {
    int matriz[T][T] = {
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
    };

    int dlarga_2 = dlarga(matriz);
    printf("La secuencia de 1s más grande es: %d\n", dlarga_2);
return 0;
}