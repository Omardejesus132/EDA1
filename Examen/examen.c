#include <stdio.h>
#include <stdlib.h>  // Para malloc(), realloc() y free()

int main() {
    int n, i, agregar;
    float *calificaciones = NULL;
    float suma = 0.0, promedio = 0.0;

    // Pedir al usuario cuántos estudiantes desea registrar inicialmente
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // Reservar memoria dinámicamente para n calificaciones
    calificaciones = (float *)malloc(n * sizeof(float));

    // Verificar si malloc() falló
    if (calificaciones == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1; // Termina el programa si no hay memoria disponible
    }

    // Capturar las calificaciones y calcular el promedio
    for (i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    // Preguntar si se desean agregar más estudiantes
    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &agregar);

    if (agregar > 0) {
        int nuevo_tamano = n + agregar;

        // Reasignar memoria para incluir las nuevas calificaciones
        float *temp = (float *)realloc(calificaciones, nuevo_tamano * sizeof(float));

        // Verificar si realloc() falló
        if (temp == NULL) {
            printf("Error: no se pudo reasignar memoria.\n");
            free(calificaciones); // Liberar la memoria previa antes de salir
            return 1;
        }

        calificaciones = temp; // Actualizar el puntero si realloc fue exitoso

        // Capturar las nuevas calificaciones
        for (i = n; i < nuevo_tamano; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        // Actualizar el número total de estudiantes
        n = nuevo_tamano;

        // Recalcular el promedio general
        promedio = suma / n;
    }

    // Mostrar todas las calificaciones y el promedio final
    printf("\n=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }

    printf("Promedio general: %.2f\n", promedio);

    // Liberar la memoria utilizada
    free(calificaciones);
    printf("Memoria liberada correctamente.\n");

    return 0; // Fin del programa
}
