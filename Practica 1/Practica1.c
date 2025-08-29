#include <stdio.h>

int main(void) {
    int n;
    int a[5];

    printf("Ingresa una cantidad (maximo 5): ");
    scanf("%d", &n);

    if (n > 5 || n < 1) {
        printf("Cantidad invalida. Debe estar entre 1 y 5.\n");
        return 1;
    }

    printf("Ingrese %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nLos elementos del array son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int suma = 0;
    int resta = a[0];
    int min = a[0], max = a[0];
    int min_index = 0, max_index = 0;

    for (int i = 0; i < n; i++) {
        suma += a[i];
        if (i > 0) {
            resta -= a[i];
        }

        if (a[i] < min) {
            min = a[i];
            min_index = i;
        }

        if (a[i] > max) {
            max = a[i];
            max_index = i;
        }
    }

    float promedio = (float)suma / n;

    printf("\nResultados:\n");
    printf("Suma: %d\n", suma);
    printf("Resta: %d\n", resta);
    printf("Promedio: %.2f\n", promedio);
    printf("Minimo: %d (indice %d)\n", min, min_index);
    printf("Maximo: %d (indice %d)\n", max, max_index);

    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("\nArreglo invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
