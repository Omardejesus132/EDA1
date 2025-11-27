PARTE 1

a) ¿Cómo se divide el problema? (Divide & Conquer)

El objetivo es encontrar el máximo elemento de un arreglo.
Con la estrategia de Divide & Conquer, el proceso es:

Dividir:
Partes el arreglo en dos mitades: izquierda y derecha.

Conquistar:
Obtienes el máximo de cada mitad recursivamente.

Commbinar:
Comparas ambos máximos y regresas el mayor.

Este enfoque reduce un problema grande de tamaño n a dos subproblemas de tamaño n/2.

b) Pseudocódigo recursivo

función maximo(A, inicio, fin):
    si inicio == fin entonces
        retornar A[inicio]   // caso base: un solo elemento

    medio = (inicio + fin) / 2

    max_izq = maximo(A, inicio, medio)
    max_der = maximo(A, medio + 1, fin)

    si max_izq > max_der entonces
        retornar max_izq
    sino
        retornar max_der

c) Explicación del caso base

El caso base ocurre cuando el arreglo ya no se puede dividir más, es decir:

Cuando inicio == fin

Solo queda un elemento en el subarreglo

En ese punto, ese único valor es necesariamente el máximo, así que se retorna.

PARTE 2

def max_recursivo(lista):
    # Función recursiva auxiliar con índices
    def max_aux(arr, inicio, fin):
        # Caso base: un solo elemento
        if inicio == fin:
            return arr[inicio]

        medio = (inicio + fin) // 2

        max_izq = max_aux(arr, inicio, medio)
        max_der = max_aux(arr, medio + 1, fin)

        return max_izq if max_izq > max_der else max_der

    # Llamada inicial
    return max_aux(lista, 0, len(lista) - 1)


# Programa principal
n = int(input("Ingresa el tamaño de la lista: "))
lista = []

print("Ingresa los elementos:")
for _ in range(n):
    valor = int(input())
    lista.append(valor)

resultado = max_recursivo(lista)
print("El valor máximo es:", resultado)
