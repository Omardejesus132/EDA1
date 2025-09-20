#include <stdio.h>
#include <string.h>

#define MAX_PELICULAS 5
#define MAX_DIRECTORES 2

struct pelicula {
    char nombre[50];
    char genero[30];
    int anio;
    int numDirectores;
    char directores[MAX_DIRECTORES][50];
};

void imprimirInverso(struct pelicula videoteca[], int n) {
    printf("\n--- Películas en orden inverso ---\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("Nombre: %s | Género: %s | Año: %d | Directores: ", 
               videoteca[i].nombre, videoteca[i].genero, videoteca[i].anio);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("%s ", videoteca[i].directores[j]);
        }
        printf("\n");
    }
}

void buscarPeliculas(struct pelicula videoteca[], int n) {
    int opcion;
    char texto[50];
    int anioBuscado;

    printf("\nBuscar por: 1) Nombre  2) Año  3) Director\nOpción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese nombre: ");
            scanf(" %[^\n]", texto);
            for (int i = 0; i < n; i++) {
                if (strcmp(videoteca[i].nombre, texto) == 0) {
                    printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
                }
            }
            break;
        case 2:
            printf("Ingrese año: ");
            scanf("%d", &anioBuscado);
            for (int i = 0; i < n; i++) {
                if (videoteca[i].anio == anioBuscado) {
                    printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
                }
            }
            break;
        case 3:
            printf("Ingrese nombre del director: ");
            scanf(" %[^\n]", texto);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < videoteca[i].numDirectores; j++) {
                    if (strcmp(videoteca[i].directores[j], texto) == 0) {
                        printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
                    }
                }
            }
            break;
        default:
            printf("Opción no válida.\n");
    }
}

void contarPorGenero(struct pelicula videoteca[], int n) {
    char generoBuscado[30];
    int contador = 0;

    printf("\nIngrese el género a contar: ");
    scanf(" %[^\n]", generoBuscado);

    for (int i = 0; i < n; i++) {
        if (strcmp(videoteca[i].genero, generoBuscado) == 0) {
            contador++;
        }
    }

    printf("Existen %d películas del género '%s'.\n", contador, generoBuscado);
}

int main() {
    struct pelicula videoteca[MAX_PELICULAS] = {
        {"Matrix", "Ciencia ficción", 1999, 2, {"Lana Wachowski", "Lilly Wachowski"}},
        {"El Padrino", "Drama", 1972, 1, {"Francis Ford Coppola"}},
        {"Titanic", "Romance", 1997, 1, {"James Cameron"}},
        {"Inception", "Ciencia ficción", 2010, 1, {"Christopher Nolan"}},
        {"Avatar", "Ciencia ficción", 2009, 1, {"James Cameron"}}
    };

    int n = 5; 

    imprimirInverso(videoteca, n);
    buscarPeliculas(videoteca, n);
    contarPorGenero(videoteca, n);

    return 0;
}
