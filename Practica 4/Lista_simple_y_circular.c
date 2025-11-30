#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr, *arr2;

    /*Reserva con malloc*/
    printf("¿Cuántos enteros quieres almacenar con malloc? ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("\nValores iniciales con malloc (basura):\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    /*Reserva calloc*/
    printf("\n¿Cuántos enteros quieres almacenar con calloc? ");
    scanf("%d", &n);

    arr2 = (int*) calloc(n, sizeof(int));

    if (arr2 == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales con calloc (todos 0):\n");
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    /*arreglo arr2*/
    printf("\nIngresa %d valores para arr2:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    /*realloc*/
    printf("\nNuevo tamaño para arr2: ");
    scanf("%d", &m);

    int *temp = realloc(arr2, m * sizeof(int));

    if (temp == NULL) {
        printf("Error: No se pudo redimensionar memoria.\n");
        free(arr);
        free(arr2);
        return 1;
    }

    arr2 = temp;

    if (m > n) {
        printf("\nIngresa los valores adicionales:\n");
        for (int i = n; i < m; i++) {
            printf("Valor %d: ", i + 1);
            scanf("%d", &arr2[i]);
        }
    }

    printf("\nValores finales en arr2:\n");
    for (int i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    /*Liberar memoria*/
    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
