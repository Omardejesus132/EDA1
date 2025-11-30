#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializar(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Error: la cola está llena, no se puede encolar %d\n", valor);
        return;
    }

    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;

    printf("Encolado: %d\n", valor);
}

int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Error: la cola está vacía, no se puede desencolar\n");
        return -1;
    }

    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;

    printf("Desencolado: %d\n", valor);
    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("La cola está vacía, no hay elemento frontal\n");
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Cola: [ ");
    for (int i = 0, idx = c->frente; i < c->size; i++, idx = (idx + 1) % MAX) {
        printf("%d ", c->datos[idx]);
    }
    printf("]\n");
}

int main() {
    ColaCircular cola;
    inicializar(&cola);

    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);

    dequeue(&cola);
    printQueue(&cola);

    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);

    printf("Elemento frontal: %d\n", peek(&cola));

    return 0;
}
