#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int arr[], int m) {
    for (int i = 0; i < m-1; i++)
        for (int j = 0; j < m-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


void selectionSort(int arr[], int m) {
    int indice;
    for (int i = 0; i < m-1; i++) {
        indice = i;
        for (int j = i+1; j < m; j++)
            if (arr[j] < arr[indice])
                indice = j;
        swap(&arr[indice], &arr[i]);
    }
}


void generador_arrays(int arr[], int m) {
    for (int i = 0; i < m; i++)
        arr[i] = rand() % 10000; 
}


void copiar_arrays(int source[], int dest[], int m) {
    for (int i = 0; i < m; i++)
        dest[i] = source[i];
}

int main() {
    int m;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &m);

    int *arr1 = (int *)malloc(m * sizeof(int));
    int *arr2 = (int *)malloc(m * sizeof(int));

    srand(time(NULL));
    generador_arrays(arr1, m);
    copiar_arrays(arr1, arr2, m);

    clock_t inicio, final;
    double tiempo_uso;

    inicio = clock();
    bubbleSort(arr1, m);
    final = clock();
    tiempo_uso = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de Bubble Sort: %.7f segundos\n", tiempo_uso);

    
    inicio = clock();
    selectionSort(arr2, m);
    final = clock();
    tiempo_uso = ((double) (final - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de Selection Sort: %.7f segundos\n", tiempo_uso);

    free(arr1);
    free(arr2);

    return 0;
}
