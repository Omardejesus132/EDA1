#include <stdio.h>

#define MAX 5

// Pila
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

// Cola
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: La pila está llena.\n");
        return;
    }
    p->datos[++p->tope] = valor;
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
    return p->datos[p->tope--];
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("[PILA VACÍA]\n");
        return;
    }
    printf("Pila: ");
    for (int i = 0; i <= p->tope; i++)
        printf("%d ", p->datos[i]);
    printf("\n");
}

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía.\n");
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: La cola está llena.\n");
        return;
    }
    c->datos[++c->final] = valor;
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: La cola está vacía.\n");
        return -1;
    }
    return c->datos[c->frente++];
}

void mostrarCola(Cola *c) {
    if (colaVacia(c)) {
        printf("[COLA VACÍA]\n");
        return;
    }
    printf("Cola: ");
    for (int i = c->frente; i <= c->final; i++)
        printf("%d ", c->datos[i]);
    printf("\n");
}

int main() {
    Pila p;
    Cola c;
    int n, valor;
    
    inicializarPila(&p);

    printf("\n¿Cuántos elementos deseas apilar? (máximo 5): ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        printf("Ingresa valor para PUSH: ");
        scanf("%d", &valor);
        push(&p, valor);
        mostrarPila(&p);
    }

    printf("\n¿Cuántos elementos deseas desapilar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int extraido = pop(&p);
        if (extraido != -1) {
            printf("Se extrajo: %d\n", extraido);
        }
        mostrarPila(&p);
    }

    printf("\n");
    inicializarCola(&c);

    printf("\n¿Cuántos elementos deseas encolar? (máximo 5): ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        printf("Ingresa valor para ENQUEUE: ");
        scanf("%d", &valor);
        enqueue(&c, valor);
        mostrarCola(&c);
    }

    printf("\n¿Cuántos elementos deseas desencolar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int extraido = dequeue(&c);
        if (extraido != -1)
            printf("Se desencoló: %d\n", extraido);
        mostrarCola(&c);
    }

    printf("\nResumen:\n");
    printf("Pila → LIFO (último en entrar, primero en salir).\n");
    printf("Cola → FIFO (primero en entrar, primero en salir).\n");

    return 0;
}
