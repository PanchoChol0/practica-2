#include <stdio.h>
#include "orden.h"

/*
Implementacion de algoritmos de ordenamiento y verificacion de tiempos de ejecucion
1.-Burbuja
2.-Seleccion
3.-Insercion
4.-Counting
5.-Bucket
6.-Timsort
7.-Quick
8.-Gnome

*/
int main() {
    int arreglo[] = {5, 2, 3, 1, 4};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    gnomeSort(arreglo, longitud);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", arreglo[i]);
    }

    return 0;
}