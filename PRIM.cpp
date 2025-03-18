/*
ANGEL EDUARDO MUÑOZ PEREZ
INGENIERIA DE SOFTWARE [CUALTOS 25A]
ANALISIS DE ALGORITMOS Prof. Hector Gonzales
*/
#include <iostream>
#include <iomanip>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <limits>  // Para limpiar el buffer de entrada
#include "colores.cpp" // Para hacer las cosas coloridas en consola
using namespace std;

// Función para generar un número aleatorio entre 1 y 10
int generarPesoAleatorio(bool permitirVacios) {
    if (permitirVacios && rand() % 2 == 0) { // uso modulo para 50% de probabilidad de ser vacío, permitirVacios es una variable booleana que el usuario activa
        return -1; // Representa un espacio vacío
    }
    return rand() % 9 + 1; // Peso aleatorio entre 1 y 10
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

/* ALGORITMO DE PRIM
	utlizamos un arreglo para almacenar los nodos que visitamos
	la variable puntero padre es para ir metiendo el nodo actual del que va cada iteracion
	la variable puntero clave es para ir metiendo el nodo con ruta mas barata del nodo padre
	el ciclo para construir el MST funciona primero:
		hacemos un for con "count" que servira para ocntar el numero de aristas totas que debe ser n-1
		u servira para asignar el nodo con peso mas barato actual de cada iteracion
		v sirve para asignar al nodo adyacente, el cual al final igualaremos a u para que en la siguiente iteracion, el nodo de menor peso sea el siguiente a evaluar como u
		para hacer la comparacion de los pesos de nodos adyacentes: 
			checa que nodo v no haya sido visitado, u == -1 es por si no se selecciono ningun nodo aun
			al final checa si la nueva clave v es mayor a u, si es menor, este lo reasignara como nueva clave
			
*/		
void primMST(int** matriz, int n) {
    color(3);
    cout << "\nAplicando el algoritmo de Prim...\n";
    color(15);

    // Arreglos para almacenar el MST
    int* padre = new int[n]; // nodo padre 
    int* clave = new int[n]; // peso mínimo 
    bool* visitado = new bool[n]; // Indica si un nodo está en el MST

    // Inicializar arreglos
    for (int i = 0; i < n; ++i) {
        clave[i] = numeric_limits<int>::max();// Inicializar con "infinito"
        visitado[i] = false; // Ningún nodo ha sido visitado
    }

    // Empezar con el nodo 0
    clave[0] = 0; // El peso para el nodo inicial es 0
    padre[0] = -1; // El nodo inicial no tiene padre

    // Construir el MST
    for (int count = 0; count < n - 1; ++count) {
	    // Seleccionar el nodo con el valor mínimo en `clave` que no esté en el MST
	    int u = -1;
	    for (int v = 0; v < n; ++v) {
	        if (!visitado[v] && (u == -1 || clave[v] < clave[u])) {
	            u = v;
	        }
	    }
	    // Agregar el nodo seleccionado al MST
	    visitado[u] = true;
	
	    // Actualizar los valores de `clave` y `padre` para los nodos adyacentes
	    for (int v = 0; v < n; ++v) {
	        // Verificar que la arista exista (matriz[u][v] != -1) y que el nodo no esté visitado
	        if (matriz[u][v] != -1 && !visitado[v] && matriz[u][v] < clave[v]) {
	            padre[v] = u;
	            clave[v] = matriz[u][v];
	        }
	    }
	}//fin del for count

    // Imprimir las aristas del MST
    color(10);
    cout << "\nAristas del Árbol de Expansión Mínima (MST):\n";
    color(15);
    for (int i = 1; i < n; ++i) {
        color(3);cout << "Arista: ";color(7);cout << padre[i] << " - " << i << " (Peso: " << matriz[i][padre[i]] << ")\n";color(15);
    }

    // Liberar memoria
    delete[] padre;
    delete[] clave;
    delete[] visitado;
}//FIN DE LA FUNCION Algoritmo de Prim//////////////////////////////////////////////////////////////

int main() {
    int n;
    color(10);
    cout << "  BIENVENIDO A MI PROGRAMA ESTIMADO :)\n         Creación de grafos " << endl;
    cout << "=========================================" << endl;
    color(11);
    cout << "Ingrese la cantidad de nodos: ";
    color(8);
    cin >> n;
    color(15);

    // Crear la matriz de adyacencia
    int** matriz = new int*[n]; // Doble puntero para apuntar tanto a los espacios de la fila de la matriz, como a las columnas que corresponden
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 0; // Inicializar la matriz con puros 0
        }
    }

    char opcion;
    color(11);
    cout << "¿Desea generar los pesos de forma aleatoria? ["; color(2); cout << "S "; color(11); cout << "/ "; color(12); cout << "N"; color(11); cout << "]"; color(15);
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        char vaciosOpcion;
        color(11);
        cout << "¿Desea permitir espacios vacíos en la matriz? ["; color(2); cout << "S "; color(11); cout << "/ "; color(12); cout << "N"; color(11); cout << "]"; color(15);
        cin >> vaciosOpcion;
        bool permitirVacios = (vaciosOpcion == 's' || vaciosOpcion == 'S');

        /* GENERAR PESOS VACIOS
            Usamos srand para asignar una semilla de aleatoriedad,
            y en cada posición usando doble bucle mandamos a llamar la función que genera los aleatorios,
            el parámetro permitirVacios solo sirve para activar la posibilidad de que haya vacíos
            admitidos, lo cual hace internamente con un if.
        */
        srand(time(0)); // Semilla para números aleatorios
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    matriz[i][j] = 0; // Para quitar los lazos en un grafo simple
                } else {
                    matriz[i][j] = generarPesoAleatorio(permitirVacios);
                }
            }
        }
    } else {
        /* INGRESAR PESOS MANUALMENTE
            Todo se desarrolla dentro de un doble bucle para recorrer la matriz,
            pedimos el peso de cada nodo con la variable input,
            primero chequeamos si pone "x" que en este caso es para indicar que no hay arista de ese nodo a nodo,
            luego pasamos y vemos si es un número con isdigit chequeando todo el string, para pasarlo después a entero con stoi.
        */
        color(3);
        cout << "Ingrese los pesos de la matriz de adyacencia "; color(1); cout << "(use 'X' para omitir una arista):\n";
        for (int i = 0; i < n; ++i) { // El doble bucle
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
                        } // FIN DEL IF VALIDAR NUMERO
                    } // Fin del if para leer pesos de nodos
                }
            } // Fin del segundo for que recorre la matriz
        } // Fin del primer for que recorre la matriz
    } // Fin del if para llenar manualmente la matriz

    // Imprimir la matriz de adyacencia
    imprimirMatriz(matriz, n);

    // Aplicar el algoritmo de Prim
    primMST(matriz, n);

    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    color(2);
    cout << "\nGracias por usar el programa. ¡Bye bye!\n";
    color(15);

    return 0;
} // FIN DEL MAIN////////////////////////////////////////////////////////////////
