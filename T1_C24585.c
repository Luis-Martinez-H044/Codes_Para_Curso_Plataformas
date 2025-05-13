#include <stdio.h>
#include <stdlib.h>

int es_binaria_y_cuadrada(FILE *archivo, int *tamano) {
    rewind(archivo);
    if (fscanf(archivo, "%d", tamano) != 1 || *tamano <= 0) {
        return 0;
    }

    int valor, contador = 0;
    while (fscanf(archivo, "%d", &valor) == 1) {
        if (valor != 0 && valor != 1) return 0;
        contador++;
    }

    return contador == (*tamano) * (*tamano);
}

void imprimir_matriz(int **matriz, int tamano) {
    printf("La matriz utilizada corresponde a:\n");
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int encontrar_diagonal_mas_larga(int **matriz, int tamano) {
    int max = 0;

    for (int col = 0; col < tamano; col++) {
        int i = 0, j = col, count = 0;
        while (i < tamano && j >= 0) {
            if (matriz[i][j] == 1) {
                count++;
                if (count > max) max = count;
            } else {
                count = 0;
            }
            i++; j--;
        }
    }

    for (int fila = 1; fila < tamano; fila++) {
        int i = fila, j = tamano - 1, count = 0;
        while (i < tamano && j >= 0) {
            if (matriz[i][j] == 1) {
                count++;
                if (count > max) max = count;
            } else {
                count = 0;
            }
            i++; j--;
        }
    }

    return max;
}

int main() {
    FILE *archivo = fopen("matriz.txt", "r");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int tamano;
    if (!es_binaria_y_cuadrada(archivo, &tamano)) {
        printf("El archivo no contiene una matriz binaria y cuadrada válida.\n");
        fclose(archivo);
        return 1;
    }

    rewind(archivo);
    fscanf(archivo, "%d", &tamano);

    int **matriz = malloc(tamano * sizeof(int *));
    for (int i = 0; i < tamano; i++)
        matriz[i] = malloc(tamano * sizeof(int));

    for (int i = 0; i < tamano; i++)
        for (int j = 0; j < tamano; j++)
            fscanf(archivo, "%d", &matriz[i][j]);

    fclose(archivo);

    imprimir_matriz(matriz, tamano);
    int resultado = encontrar_diagonal_mas_larga(matriz, tamano);
    printf("La secuencia de 1s más grande es: %d\n", resultado);

    for (int i = 0; i < tamano; i++)
        free(matriz[i]);
    free(matriz);

return 0;
}