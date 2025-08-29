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

    return 0;
}
