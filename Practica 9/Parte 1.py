x = 10
print (x)
cadena = "Hola mundo"
print (cadena)

x = y = z = 10
print (x,y,z)

type(x)
print (type(x))
type(cadena)
print (type(cadena))

x = "Hola mundo"
print(x)
cadena = 10
print(cadena)
type(x)
print (type(x))
type(cadena)
print (type(cadena))

SEGUNDOS_POR_DIA = 60 * 60 * 24
print (SEGUNDOS_POR_DIA)
PI = 3.14
print (PI)

cadena1 = 'Hola '
cadena2 = "Mundo"
print(cadena1)
print(cadena2)
concat_cadenas = cadena1 + cadena2
print(concat_cadenas)

num_cadena = concat_cadenas +' '+ str(3)
print(num_cadena)

num_cadena = "{} {} {}". format(cadena1, cadena2, 3)
print(num_cadena)

num_cadena = "Cambiando el orden: {1} {2} {0} #".format(cadena1, cadena2, 3)
print(num_cadena)

print( 1 + 5 )
print( 6 * 3 )
print( 10 - 4 )
print( 100 / 50 )
print( 10 % 2  )
print( ((20 * 3 )+ (10 + 1 )) / 10 )
print( 2 * 2 )

print (7 < 5)
print(7 > 5)
print((11 * 3)+2 == 36 - 1)
print((11 * 3)+2 >= 36)
print("curso" != "CuRsO")

lista_diasDelMes=[31,28,31,30,31,30,31,31,30,31,30,31]

print (lista_diasDelMes)
print (lista_diasDelMes[0])
print (lista_diasDelMes[6])
print (lista_diasDelMes[11])

lista_numeros=[['cero', 0],['uno',1, 'UNO'], ['dos',2],['tres', 3], ['cuatro',4], ['X',5]]

print (lista_numeros)

print(lista_numeros[0])
print(lista_numeros[1])

print(lista_numeros[2][0])
print(lista_numeros[2][1])

print(lista_numeros[1][0])
print(lista_numeros[1][1])
print(lista_numeros[1][2])

lista_numeros[5][0] = 'cinco'
print(lista_numeros[5])

tupla_diaDelMes=(31,28,31,30,31,30,31,31,30,31,30,31)

print (tupla_diaDelMes)
print(tupla_diaDelMes[0])
print(tupla_diaDelMes[3])
print (tupla_diaDelMes[1])

tupla_numeros=(('cero', 0),('uno',1, 'UNO'), ('dos',2), ('tres', 3), ('cuatro',4), ('X',5))

print (tupla_numeros)

print (tupla_numeros[0])
print (tupla_numeros[1])

print (tupla_numeros[2][0])
print (tupla_numeros[2][1])

print (tupla_numeros[1][0])
print (tupla_numeros[1][1])
print (tupla_numeros[1][2])

print("valor actual {}".format(lista_diasDelMes[0]))
lista_diasDelMes[0] = 50
print("valor cambiado {}".format(lista_diasDelMes[0]))
tupla_diasDelMes[0] = 50

#Aqui lo corte porque en la practica viene el ejemplo de que marca un error
