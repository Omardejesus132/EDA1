#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;

    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía\n");
        return;
    }

    struct Nodo *temp = inicio;
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("(inicio)\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *temp = *inicio;
    struct Nodo *ultimo = (*inicio)->anterior;

    do {
        if (temp->dato == valor)
            break;
        temp = temp->siguiente;
    } while (temp != *inicio);

    if (temp->dato != valor) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (temp->siguiente == temp && temp->anterior == temp) {
        free(temp);
        *inicio = NULL;
        printf("Nodo eliminado y lista vacía.\n");
        return;
    }

    if (temp == *inicio) {
        *inicio = temp->siguiente;
    }

    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;

    free(temp);
    printf("Nodo eliminado.\n");
}

void liberar(struct Nodo **inicio) {
    if (*inicio == NULL) return;

    struct Nodo *temp = (*inicio)->siguiente;
    struct Nodo *borrar;

    while (temp != *inicio) {
        borrar = temp;
        temp = temp->siguiente;
        free(borrar);
    }

    free(*inicio);
    *inicio = NULL;

    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores quieres insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerCircular(inicio);
    }

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);

    printf("Lista actualizada:\n");
    recorrerCircular(inicio);

    liberar(&inicio);

    return 0;
}
