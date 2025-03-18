/*
ANGEL EDUARDO MUÑOZ PEREZ
INGENIERIA DE SOFTWARE [CUALTOS 25A]
ANALISIS DE ALGORTIMOS Prof. Hector Gonzales
ALGORITMO DE FLYNN
*/
#include <iostream>
#include <iomanip>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <limits>  // Para limpiar el buffer de entrada
#include "colores.cpp" //para hacer las cosas coloridas en consola
using namespace std;

// Función para generar un número aleatorio entre 1 y 10
int generarPesoAleatorio(bool permitirVacios) {
    if (permitirVacios && rand() % 2 == 0) { // uso modulo para 50% de probabilidad de ser vacío, permitirVacios es una variable booleana que el usuario activa
        return -1; // Representa un espacio vacío
    }
    return rand() % 10 + 1; // Peso aleatorio entre 1 y 10
}//FIN DE FUNCION ALEATORIA////////////////////////////////////////////////////////////////

// Función para imprimir la matriz de adyacencia
void imprimirMatriz(int** matriz, int n) {
    color(2);
    cout << endl << "Matriz de Adyacencia:" << endl;
    color(15);
    cout << setw(5) << " ";
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i;
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == -1) {
                cout << setw(5) << "X"; // Mostrar "X" para espacios vacíos
            } else {
                cout << setw(5) << matriz[i][j];
            }
        }
        cout << endl;
    }
}//FIN DE FUNCION PARA IMPRIMIR MATRIZ////////////////////////////////////////////////////////

/* ALGORIMTO DE FLOYD-WARSHALL
	Copea la matriz que ya hicimos en el programa
	para hacer las sumas correspondientes y comparacion del algoritmo
		bucle for(k) sirve para hacer iteracion sobre todos los nodos
		bucle for(i) para moverse sobre los nodos origen
		bucle for(j) para moverse sobre los nodos destino
		para cada combinación de nodos (i, j), el algoritmo verifica si pasar por el nodo k como intermediario resulta en un camino más corto.
*/
void floydWarshall(int** matriz, int n) {
    // Crear una copia de la matriz de adyacencia para trabajar con ella
    int** distancias = new int*[n];
    for (int i = 0; i < n; ++i) {
        distancias[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                distancias[i][j] = 0; // La distancia de un nodo a sí mismo es 0
            } else if (matriz[i][j] != -1) {
                distancias[i][j] = matriz[i][j]; // Usar el peso de la arista si existe
            } else {
                distancias[i][j] = 9999; // Infinito (representado por un número grande)
            }
        }
    }

    // Aplicar el algoritmo de Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distancias[i][k] + distancias[k][j] < distancias[i][j]) {
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
                }
            }
        }
    }

    // Imprimir la matriz de distancias más cortas
    color(2);
    cout << endl << "Matriz de Floyd-Warshall (Distancias más cortas):" << endl;
    color(15);
    cout << setw(5) << " ";
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i;
        for (int j = 0; j < n; ++j) {
            if (distancias[i][j] == 9999) {
                cout << setw(5) << "INF"; // Mostrar "INF" para distancias infinitas
            } else {
                cout << setw(5) << distancias[i][j];
            }
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] distancias[i];
    }
    delete[] distancias;
}//FIN DE LA FUNCIÓN FLOYD-WARSHALL////////////////////////////////////////////////////////

int main() {
    int n;
    color(10);
    cout << "  BIENVENIDO A MI PROGRAMA ESTIMADO :)\n         creacion de grafos " << endl;
    cout << "=========================================" << endl;
    color(11);
    cout << "Ingrese la cantidad de nodos: ";
    color(8);
    cin >> n;
    color(15);

    // Crear la matriz de adyacencia
    int** matriz = new int*[n]; //doble puntero para apuntar tanto a los espacios de la fila de la matriz, como a las columnas que corresponden
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 0; // Inicializar la matriz con puros 0
        }
    }

    char opcion;
    color(11);
    cout << "¿Desea generar los pesos de forma aleatoria? [";
    color(2);
    cout << "S ";
    color(11);
    cout << "/ ";
    color(12);
    cout << "N";
    color(11);
    cout << "]";
    color(15);
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        char vaciosOpcion;
        color(11);
        cout << "¿Desea permitir espacios vacios en la matriz? [";
        color(2);
        cout << "S ";
        color(11);
        cout << "/ ";
        color(12);
        cout << "N";
        color(11);
        cout << "]";
        color(15);
        cin >> vaciosOpcion;
        bool permitirVacios = (vaciosOpcion == 's' || vaciosOpcion == 'S');

        /* GENERAR PESOS VACIOS
            usamos srand para asignar una semilla de aleatoriedad,
            y en cada posición usando doble bucle mandamos a llamar la función que genera los aleatorios,
            el parámetro permitirVacios solo sirve para activar la posibilidad de que haya vacíos
            admitidos, lo cual hace internamente con un if
        */
        srand(time(0)); // Semilla para números aleatorios
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    matriz[i][j] = 0; // para quitar los lazos en un grafo simple
                } else {
                    matriz[i][j] = generarPesoAleatorio(permitirVacios);
                }
            }
        }
    } else {
        /* INGRESAR PESOS MANUALMENTE
            todo se desarrolla dentro de un doble bucle para recorrer la matriz,
            pedimos el peso de cada nodo con la variable input,
            primero chequeamos si pone "x" que en este caso es para indicar que no hay arista de ese nodo a nodo,
            luego pasamos y vemos si es un número con isdigit chequeando todo el string, para pasarlo después a entero con stoi
        */
        color(3);
        cout << "Ingrese los pesos de la matriz de adyacencia ";
        color(1);
        cout << "(use 'X' para omitir una arista):\n";
        for (int i = 0; i < n; ++i) { //el doble bucle
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    matriz[i][j] = 0; // No hay lazos en un grafo simple
                } else {
                    string input;
                    color(7);
                    cout << "Peso del nodo " << i << " al nodo " << j << " (o 'X' para omitir): ";
                    color(8);
                    cin >> input;
                    color(15);

                    // Verificar si la entrada es 'X' o 'x'
                    if (input == "X" || input == "x") { // Representa un espacio vacío si detecta que el usuario metió x
                        matriz[i][j] = -1;
                    } else {
                        // Intentar convertir la entrada a un número
                        bool esNumero = true;
                        for (char c : input) {
                            if (!isdigit(c)) {
                                esNumero = false;
                                break;
                            }
                        }
                        if (esNumero) {
                            matriz[i][j] = stoi(input); // Convertir a entero
                        } else {
                            color(12);
                            cout << "Entrada no válida. Se usará 0 como valor predeterminado.\n";
                            color(15);
                            matriz[i][j] = 0;
                        } //FIN DEL IF VALIDAR NUMERO
                    } //fin del if para leer pesos de nodos
                }
            } //fin del segundo for que recorre la matriz
        } //fin del primer for que recorre la matriz
    } //fin del if para llenar manualmente la matriz

    // Imprimir la matriz de adyacencia
    imprimirMatriz(matriz, n);

    // Aplicar el algoritmo de Floyd-Warshall
    floydWarshall(matriz, n);

    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}//FIN DEL MAIN////////////////////////////////////////////////////////////////
