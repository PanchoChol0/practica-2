#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "orden.h" // Asegúrate de incluir tus funciones de ordenamiento aquí

// Función para generar un arreglo de números aleatorios de tamaño n
void generarArregloAleatorio(int arr[], int n) {
    srand(time(NULL)); // Inicializar la semilla para números aleatorios

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Genera números aleatorios entre 0 y 999 (puedes ajustar el rango)
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void medirTiempo(void (*ordenamiento)(int[], int), int arr[], int longitud, const char* nombre) {
    clock_t inicio, fin;
    double tiempo;

    inicio = clock();
    ordenamiento(arr, longitud);
    fin = clock();

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución de %s: %lf segundos\n", nombre, tiempo);
}

int main() {
    int n = 10; // Tamaño del arreglo aleatorio

    int arreglo[n];

    // Generar el arreglo aleatorio
    generarArregloAleatorio(arreglo, n);

    printf("Arreglo aleatorio:\n");
    imprimirArreglo(arreglo, n);

    // Medir el tiempo de ejecución del algoritmo Gnome Sort
    medirTiempo(gnomeSort, arreglo, n, "Gnome Sort");

    printf("Arreglo ordenado:\n");
    imprimirArreglo(arreglo, n);

    return 0;
}
