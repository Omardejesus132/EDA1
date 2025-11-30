#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

void insertarInicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
    printf("Insertado: %d\n", valor);
}

void recorrer(Nodo *cabeza) {
    Nodo *temp = cabeza;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    }
    printf("NULL\n");
}

void eliminar(Nodo **cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía\n");
        return;
    }

    Nodo *temp = *cabeza;
    Nodo *anterior = NULL;

    if (temp->dato == valor) {
        *cabeza = temp->sig;
        free(temp);
        printf("Eliminado: %d\n", valor);
        return;
    }

    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->sig;
    }

    if (temp == NULL) {
        printf("El valor %d no está en la lista\n", valor);
        return;
    }

    anterior->sig = temp->sig;
    free(temp);

    printf("Eliminado: %d\n", valor);
}

void liberar(Nodo *cabeza) {
    Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->sig;
        free(temp);
    }
    printf("Memoria liberada correctamente\n");
}

int main() {
    Nodo *cabeza = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta un valor: ");
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("\nContenido actual de la lista:\n");
    recorrer(cabeza);

    printf("\n¿Qué valor deseas eliminar?: ");
    scanf("%d", &eliminarValor);

    eliminar(&cabeza, eliminarValor);

    printf("\nLista después de eliminar:\n");
    recorrer(cabeza);

    liberar(cabeza);

    return 0;
}
