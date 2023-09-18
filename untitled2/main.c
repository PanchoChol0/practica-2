#include <stdio.h>
#include <time.h>
#include "orden.h"

// Función para medir el tiempo de ejecución de una función de ordenamiento
void medirTiempo(void (*ordenamiento)(int[], int), int arr[], int longitud, const char* nombre) {
    clock_t inicio, fin;
    double tiempo;

    inicio = clock();
    ordenamiento(arr, longitud);
    fin = clock();

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion de %s: %lf segundos\n", nombre, tiempo);
}

int main() {
    int arreglo[] = {5, 2, 3, 1, 4};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    // Medir el tiempo de ejecución del algoritmo Gnome Sort
    medirTiempo(gnomeSort, arreglo, longitud, "Gnome Sort");

    printf("Arreglo ordenado: ");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", arreglo[i]);
    }

    return 0;
}