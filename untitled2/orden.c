//
// Created by 52552 on 18/09/2023.
//
#include "orden.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN_MERGE 32

void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void burbuja(int arreglo[], int longitud) {
    for (int x = 0; x < longitud; x++) {
        for (int indiceActual = 0; indiceActual < longitud - 1; indiceActual++) {
            int indiceSiguienteElemento = indiceActual + 1;
            if (arreglo[indiceActual] > arreglo[indiceSiguienteElemento]) {
                intercambiar(&arreglo[indiceActual], &arreglo[indiceSiguienteElemento]);
            }
        }
    }
}

void seleccion(int arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < longitud; j++) {
            if (arreglo[j] < arreglo[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            intercambiar(&arreglo[i], &arreglo[indiceMenor]);
        }
    }
}

void insercion(int arreglo[], int longitud) {
    for (int i = 1; i < longitud; i++) {
        int valorActual = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > valorActual) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = valorActual;
    }
}

void counting(int arreglo[], int longitud) {
    int max = 0;
    for (int i = 0; i < longitud; i++) {
        if (arreglo[i] > max) {
            max = arreglo[i];
        }
    }

    int conteo[max + 1];
    for (int i = 0; i < max + 1; i++) {
        conteo[i] = 0;
    }

    for (int i = 0; i < longitud; i++) {
        conteo[arreglo[i]]++;
    }

    int indiceArreglo = 0;
    for (int i = 0; i < max + 1; i++) {
        while (conteo[i] > 0) {
            arreglo[indiceArreglo] = i;
            indiceArreglo++;
            conteo[i]--;
        }
    }
}

void bucketSort(int arreglo[], int longitud) {
    if (longitud <= 0) return;

    // Encontramos el valor máximo en el arreglo
    int max = arreglo[0];
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] > max) {
            max = arreglo[i];
        }
    }

    // Creamos los cubos (buckets)
    int *buckets = (int *)malloc(sizeof(int) * (max + 1));
    if (buckets == NULL) {
        printf("Error de asignación de memoria\n");
        return;
    }

    // Inicializamos todos los cubos a 0
    for (int i = 0; i <= max; i++) {
        buckets[i] = 0;
    }

    // Colocamos los elementos en los cubos
    for (int i = 0; i < longitud; i++) {
        buckets[arreglo[i]]++;
    }

    // Recorremos los cubos y colocamos los elementos en el arreglo original
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (buckets[i] > 0) {
            arreglo[index++] = i;
            buckets[i]--;
        }
    }

    // Liberamos la memoria de los cubos
    free(buckets);
}

// TIMSORT
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void merge(int arreglo[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arreglo[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arreglo[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arreglo[k] = L[i];
            i++;
        } else {
            arreglo[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arreglo[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arreglo[k] = R[j];
        j++;
        k++;
    }
}

// Función de ordenamiento por Timsort
void timsort(int arreglo[], int longitud) {
    if (longitud <= 0) return;

    // Ordenar pequeños subarreglos usando insertion sort
    for (int i = 0; i < longitud; i += MIN_MERGE) {
        int left = i;
        int right = (i + MIN_MERGE - 1 < longitud - 1) ? (i + MIN_MERGE - 1) : (longitud - 1);
        qsort(&arreglo[left], right - left + 1, sizeof(int), comparar);
    }

    // Fusionar subarreglos en uno solo
    for (int size = MIN_MERGE; size < longitud; size = 2 * size) {
        for (int left = 0; left < longitud; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < longitud - 1) ? (left + 2 * size - 1) : (longitud - 1);
            if (mid < right) {
                merge(arreglo, left, mid, right);
            }
        }
    }
}

// Función de partición para el algoritmo Quick Sort
int particion(int arreglo[], int low, int high) {
    int pivot = arreglo[high]; // Tomamos el último elemento como pivote
    int i = (low - 1); // El índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arreglo[j] <= pivot) {
            i++; // Incrementamos el índice del elemento más pequeño
            // Intercambiamos arr[i] y arr[j]
            int temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
        }
    }

    // Intercambiamos arr[i+1] y arr[high] (el pivote)
    int temp = arreglo[i + 1];
    arreglo[i + 1] = arreglo[high];
    arreglo[high] = temp;

    return (i + 1);
}

// Función recursiva para el algoritmo Quick Sort
void quickSort(int arreglo[], int low, int high) {
    if (low < high) {
        // Encontramos el índice del elemento pivote
        int pi = particion(arreglo, low, high);

        // Ordenamos los elementos antes y después de la partición
        quickSort(arreglo, low, pi - 1);
        quickSort(arreglo, pi + 1, high);
    }
}

void gnomeSort(int arreglo[], int longitud) {
    int index = 0;

    while (index < longitud) {
        if (index == 0) {
            index++;
        }
        if (arreglo[index] >= arreglo[index - 1]) {
            index++;
        } else {
            // Intercambiar elementos si están en el orden incorrecto
            int temp = arreglo[index];
            arreglo[index] = arreglo[index - 1];
            arreglo[index - 1] = temp;
            index--;
        }
    }
}

