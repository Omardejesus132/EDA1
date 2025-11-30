#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

void inicializar(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado\n");
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

int isFull(Deque *d) {
    return d->size == MAX;
}

int getRear(Deque *d) {
    if (isEmpty(d)) return -1;
    return (d->front + d->size - 1) % MAX;
}

void insert_front(Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: el deque está lleno, no se puede insertar al frente %d\n", valor);
        return;
    }

    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;

    printf("Insertado al frente: %d\n", valor);
}

void insert_rear(Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: el deque está lleno, no se puede insertar al final %d\n", valor);
        return;
    }

    int rear = (d->front + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;

    printf("Insertado al final: %d\n", valor);
}

int delete_front(Deque *d) {
    if (isEmpty(d)) {
        printf("Error: el deque está vacío, no se puede eliminar del frente\n");
        return -1;
    }

    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;

    printf("Eliminado del frente: %d\n", valor);
    return valor;
}

int delete_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("Error: el deque está vacío, no se puede eliminar del final\n");
        return -1;
    }

    int rear = getRear(d);
    int valor = d->datos[rear];
    d->size--;

    printf("Eliminado del final: %d\n", valor);
    return valor;
}

int peek_front(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque vacío, no hay frente\n");
        return -1;
    }
    return d->datos[d->front];
}

int peek_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque vacío, no hay final\n");
        return -1;
    }
    return d->datos[getRear(d)];
}

void printDeque(Deque *d) {
    printf("Deque: [ ");
    for (int i = 0, idx = d->front; i < d->size; i++, idx = (idx + 1) % MAX) {
        printf("%d ", d->datos[idx]);
    }
    printf("]\n");

    printf("front = %d\n", d->front);
    printf("rear  = %d\n", getRear(d));
}

int main() {
    Deque d;
    inicializar(&d);

    insert_front(&d, 10);

    insert_rear(&d, 15);
    insert_rear(&d, 20);

    insert_front(&d, 30);

    insert_rear(&d, 40);
    printDeque(&d);

    delete_front(&d);
    delete_rear(&d);
    printDeque(&d);

    insert_front(&d, 99);
    insert_rear(&d, 77);
    insert_front(&d, 55);
    printDeque(&d);

    return 0;
}
