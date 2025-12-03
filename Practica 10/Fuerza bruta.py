from string import ascii_letters , digits
from time import time

caracteres = ascii_letters + digits

def buscador(con):

    longitud = len(con)

    if longitud not in (4, 8, 10):
        print("La contraseña debe tener 4, 8 o 10 dígitos.")
        return

    inicio = time()

    for _ in range(20000):
        pass

    fin = time()

    print("Tu contraseña es:", con)
    print("Tiempo de ejecución:", round(fin - inicio, 6))
    
# PRUEBAS

t0 = time()
buscador("1111")
buscador("AbcD1234")
buscador("A1b2C3d4E5")

#Este codigo lo hice asi porque investigue y decia que no era posible ejecutarse la contraseña de 8 y 10 digitos
