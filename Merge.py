from random import random

"""
Ordena una lista utilizando el algoritmo de ordenación por mezcla (merge sort).
Args:
    array (list): Lista de elementos a ordenar.
Returns:
    list: Lista ordenada.
"""
def ordenar_por_mezcla(array):
    if len(array) <= 1:
        return array
    
    mitad = len(array) // 2
    izquierda = ordenar_por_mezcla(array[:mitad])
    derecha = ordenar_por_mezcla(array[mitad:])
    
    return mezclar(izquierda, derecha)

"""
Mezcla dos listas ordenadas en una sola lista ordenada.
Args:
    izquierda (list): Primera lista ordenada.
    derecha (list): Segunda lista ordenada.
Returns:
    list: Lista combinada y ordenada.
"""
def mezclar(izquierda, derecha):
    array_ordenado = []
    i = j = 0
    
    while i < len(izquierda) and j < len(derecha):
        if izquierda[i] < derecha[j]:
            array_ordenado.append(izquierda[i])
            i += 1
        else:
            array_ordenado.append(derecha[j])
            j += 1
    
    array_ordenado.extend(izquierda[i:])
    array_ordenado.extend(derecha[j:])
    
    return array_ordenado

"""
Realiza una búsqueda binaria en una lista ordenada.
Args:
    array_entrada (list): Lista ordenada en la que se realizará la búsqueda.
    busqueda (int): Elemento a buscar en la lista.
Returns:
    tuple: Una tupla que contiene el elemento encontrado y un booleano indicando si fue encontrado.
           Si el elemento no se encuentra, retorna "No encontrado".
"""

def binary_search(array_entrada, busqueda):
    if len(array_entrada) == 0:
        return "No encontrado"
    
    mitad = len(array_entrada) // 2
    if array_entrada[mitad] == busqueda:
        return busqueda, True
    elif array_entrada[mitad] < busqueda:
        return binary_search(array_entrada[mitad + 1:], busqueda)
    else:
        return binary_search(array_entrada[:mitad], busqueda)

while True:
    print("""\033[1m \033[33m
   _____                               _________              __      ____    __________  _________                           .__     
  /     \   ___________  ____   ____  /   _____/ ____________/  |_   /  _ \   \______   \/   _____/ ____ _____ _______   ____ |  |__  
 /  \ /  \_/ __ \_  __ \/ ___\_/ __ \ \_____  \ /  _ \_  __ \   __\  >  _ </\  |    |  _/\_____  \_/ __ \\\\__  \\\\_  __ \_/ ___\|  |  \\
/    Y    \  ___/|  | \/ /_/  >  ___/ /        (  <_> )  | \/|  |   /  <_\ \/  |    |   \/        \  ___/ / __ \|  | \/\  \___|   Y  \\
\____|__  /\___  >__|  \___  / \___  >_______  /\____/|__|   |__|   \_____\ \  |______  /_______  /\___  >____  /__|    \___  >___|  /
        \/     \/     /_____/      \/        \/                            \/         \/        \/     \/     \/            \/     \/ 
\033[0m""")

    array = []

    n = int(input("Ingrese el tamaño del array: "))

    for i in range(n):
        array.append(int(random() * 100))
        print(f"Termino: {array[i]}")

    print(f"Array desordenado: {array}")
    array_ordenado = ordenar_por_mezcla(array)
    
    print(f"Array ordenado: {array_ordenado}")
    buscar = int(input("Ingrese el número a buscar: "))
    
    print(f"Encontrado?: {binary_search(array_ordenado, buscar)}")  
    print("Deseas continuar? (s/n)")

    continuar = input()
    if continuar == "n":
        break