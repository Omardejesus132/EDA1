#include <stdio.h>

int main(void) {
    int a[5] = {2, 4, 6, 8, 10};  // Declaración de un arreglo de 5 enteros
    int *p = a; // p apunta al primer elemento del arreglo (a[0])

    printf("1) a[1] = %d\n", a[1]); 
    // Imprime el segundo elemento del arreglo (a[1] = 4)

    printf("2) *(a+3) = %d\n", *(a+3)); 
    // Usa aritmética de punteros: *(a + 3) es a[3], que vale 8

    printf("3) *p++ = %d\n", *p++); 
    // Post-incremento: primero se evalúa *p (es decir, a[0] = 2)
    // Luego p avanza a la siguiente posición (ahora apunta a a[1])

    printf("4) *++p = %d\n", *++p); 
    // Pre-incremento: primero p avanza (ahora apunta a a[2])
    // Luego se evalúa *p (es decir, a[2] = 6)

    printf("5) p[1] = %d\n", p[1]); 
    // p apunta a a[2], así que p[1] es a[3], que vale 8

    printf("6) *(p+=2) = %d\n", *(p+=2)); 
    // p avanza dos posiciones (de a[2] a a[4])
    // Luego se evalúa *p (es decir, a[4] = 10)

    printf("7) p - a = %ld\n", p - a); 
    // Resta de punteros: cuántos elementos hay entre p (a[4]) y a (a[0])
    // Resultado: 4

    return 0;
}