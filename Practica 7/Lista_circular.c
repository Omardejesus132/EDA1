#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

void insertarInicioCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->sig = nuevo;
    } else {
        nuevo->sig = *cabeza;
        (*ultimo)->sig = nuevo;
        *cabeza = nuevo;
    }

    printf("Insertado (circular): %d\n", valor);
}

void recorrerCircular(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    Nodo *temp = cabeza;

    printf("Lista circular: ");
    do {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    } while (temp != cabeza);

    printf("(regresa a cabeza)\n");
}

void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía, no se puede eliminar\n");
        return;
    }

    Nodo *temp = *cabeza;
    Nodo *anterior = *ultimo;

    if (temp->dato == valor) {
        if (*cabeza == *ultimo) {
            free(temp);
            *cabeza = NULL;
            *ultimo = NULL;
        } else {
            *cabeza = temp->sig;
            (*ultimo)->sig = *cabeza;
            free(temp);
        }
        printf("Eliminado (circular): %d\n", valor);
        return;
    }

    do {
        if (temp->dato == valor) break;
        anterior = temp;
        temp = temp->sig;
    } while (temp != *cabeza);

    if (temp == *cabeza) {
        printf("El valor %d no está en la lista\n", valor);
        return;
    }

    anterior->sig = temp->sig;

    if (temp == *ultimo) {
        *ultimo = anterior;
    }

    free(temp);
    printf("Eliminado (circular): %d\n", valor);
}

void liberarCircular(Nodo *cabeza) {
    if (cabeza == NULL) return;

    Nodo *temp = cabeza->sig;
    Nodo *siguiente;

    while (temp != cabeza) {
        siguiente = temp->sig;
        free(temp);
        temp = siguiente;
    }

    free(cabeza);
    printf("Memoria liberada correctamente\n");
}

int main() {
    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta un valor: ");
        scanf("%d", &valor);
        insertarInicioCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("\nRecorrido completo de la lista circular:\n");
    recorrerCircular(cabeza);

    printf("\n¿Qué valor deseas eliminar?: ");
    scanf("%d", &eliminarValor);

    eliminarCircular(&cabeza, &ultimo, eliminarValor);

    printf("\nLista después de eliminar:\n");
    recorrerCircular(cabeza);
    
    liberarCircular(cabeza);

    return 0;
}
