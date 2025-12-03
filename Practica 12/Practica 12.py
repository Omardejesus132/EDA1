def fibonacci_iterativo_v1(numero):
    f1=0
    f2=1
    tmp=0
    for i in range(1,numero-1):
        tmp = f1+f2
        f1=f2
        f2=tmp
    return f2
print(fibonacci_iterativo_v1(6))

def fibonacci_iterativo_v2(numero):
    f1=0
    f2=1
    for i in range(1, numero-1):
        f1,f2=f2,f1+f2 
    return f2
print(fibonacci_iterativo_v2(6))

def fibonacci_bottom_up(numero):
    f_parciales = [0, 1, 1]
    while len(f_parciales) < numero:
        f_parciales.append(f_parciales[-1] + f_parciales[-2])
        print(f_parciales)
    return f_parciales[numero-1]
print(fibonacci_bottom_up(5))

memoria = {1:0, 2:1, 3:1}

def fibonacci_top_down(numero):
    if numero in memoria:
        return memoria[numero]
    f = fibonacci_iterativo_v2(numero-1) + fibonacci_iterativo_v2(numero-2)
    memoria[numero] = f
    return memoria[numero]
print(fibonacci_top_down(12))
print(memoria)
print(fibonacci_top_down(8))
print(memoria)

import pickle

archivo = open('memoria.p', 'wb')
pickle.dump(memoria, archivo)
archivo.close()


#Leer variable
archivo = open('memoria.p', 'rb')
memoria_de_archivo = pickle.load(archivo)
archivo.close()

print(memoria)
print(memoria_de_archivo)

def quicksort(lista):
    quicksort_aux(lista,0,len(lista)-1)

def quicksort_aux(lista,inicio, fin):
    if inicio < fin:

        pivote = particion(lista,inicio,fin)

        quicksort_aux(lista, inicio, pivote-1)
        quicksort_aux(lista, pivote+1, fin)

def particion(lista, inicio, fin):

    pivote = lista[inicio]
    print("Valor del pivote {}".format(pivote))

    izquierda = inicio+1
    derecha = fin
    print("Indice izquierdo {}".format(izquierda))
    print("Indice derecho {}".format(derecha))

    bandera = False
    while not bandera:
        while izquierda <= derecha and lista[izquierda] <= pivote:
            izquierda = izquierda + 1
        while lista[derecha] >= pivote and derecha >=izquierda:
            derecha = derecha -1
        if derecha < izquierda:
            bandera= True
        else:
            temp=lista[izquierda]
            lista[izquierda]=lista[derecha]
            lista[derecha]=temp

    print(lista)

    temp=lista[inicio]
    lista[inicio]=lista[derecha]
    lista[derecha]=temp
    return derecha

lista = [21, 10, 0, 11, 9, 24, 20, 14, 1]
print("lista desordenada {}".format(lista))
quicksort(lista)
print("lista ordenada {}".format(lista))





