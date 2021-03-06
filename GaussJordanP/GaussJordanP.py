# -*- coding: utf-8 -*-
"""GaussJordanP

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1ORg-CXX6G7zgxRYecjQ0bLCgQMiEjjWX
"""

# Martin Morales Trejo
# Método Gauss-Jordan
# Nov 20, 2021

# Se importan las siguientes librerías
#Numpy nos sirve para implementar arreglos con distintas variables
import numpy as np 
#Por otro lado, Sys nos servirá para evitar el error cuando se divida entre 0
import sys

# 1) Primeramente se solicita el numero de ecuaciónes con las que cuenta el 
# usuario, lo anterior se guarda en la variable I de tipo entero.
I = int(input('Número de ecuaciones: '))

# 2) Posteriormente se concluye que el número de ecuaciones es igual al número
# de incógnitas, por lo que se procede a hacer una matrix cuadrada de tamaño I, 
# a la cuál se le concatena otra columna a la derecha (la de solución), teniendo
# el nombre de M.
M = np.zeros((I,I + 1))

# 3) Lo siguiente es plantear el vector columna en forma de arreglo
x = np.zeros((I , 1))

#Nota: np.zeros nos permite inicializar con ceros

# 4) El siguiente paso es solicitar los coeficientes de la matriz aumentada
print(' ')
for i in range(I):
  for j in range(I + 1):
    M [i][j] = float(input('Valor elemento [' + str(i) +'][' + str(j) + ']: '))

# 5) Una vez que ya tenemos los coeficientes de la matriz aumentada, procedemos
# a implementar el método de gauss-jordan
for i in range(I):
  if M[i][j] == 0.0:
    sys.exit('Alto! Divides entre 0!') #Mensaje de error, lo que a su vez 
    # termina la ejecución del código 
  for j in range(I): 
    if i != j:
      d = M[j][i] / M[i][i]
      for k in range (I + 1):
        M[j][k] = M[j][k] - d * M[i][k]
#Nota: La solución estará dada por:
for i in range (I):
  x[i] = M[i][I] / M[i][i]

# 6) Finalmente se imprime el resultado en pantalla
print('\nSolución: ')
for i in range(I):
  print('x%d = %0.0f' %(i, x[i]), end = '\n')
