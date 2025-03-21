/*
ANGEL EDUARDO MU?OZ PEREZ
INGENIERIA DE SOFTWARE [CUALTOS 25A]
ANALISIS DE ALGORTIMOS Prof. Hector Gonzales
ALGORITMO DE KRUSKAL
*/
#include <iostream>
#include <iomanip>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <limits>  // Para limpiar el buffer de entrada
#include "colores.cpp"//para hacer las cosas coloridas en consola
#include <algorithm> // Para sort()
#include <vector>    // Para vector
using namespace std;

// Funci?n para generar un n?mero aleatorio entre 1 y 10
int generarPesoAleatorio(bool permitirVacios) {
    if (permitirVacios && rand() % 4 == 0) { // uso modulo para 50% de probabilidad de ser vac?o, permitirVacios es una variable booleana que el usuario ativa
        return -1; // Representa un espacio vac?o
    }
    return rand() % 10 + 1; // Peso aleatorio entre 1 y 10
}//FIN DE FUNCION ALEATORIA////////////////////////////////////////////////////////////////

// Funci?n para imprimir la matriz de adyacencia
void imprimirMatriz(int** matriz, int n) {
	color(2);
    cout <<endl<< "Matriz de Adyacencia:"<<endl;color(15);
    cout << setw(5) << " ";
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(5) << i;
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == -1) {
                cout << setw(5) << "X"; // Mostrar "X" para espacios vac?os
            } else {
                cout << setw(5) << matriz[i][j];
            }
        }
        cout << endl;
    }
}//FIN DE FUNCNION PARA IMPRIMIR MATRIZ////////////////////////////////////////////////////////

/*
	KRUSKAL como funciona
		PRIMERO: recorremos la matriz y almacenamos de donde vino, a donde fue y el peso en la estructura Arista
		luego ordenamos estas aristas por peso
		a partir de ahi encontrarPadre y unirConjuntos se usan para manejar los conjuntos disjuntos
		para detectar ciclos en el algoritmo de Kruskal. 
		Si padre[i] == i, significa que i es su propio padre, por lo que es la raíz del conjunto.
		Si no, se llama recursivamente a encontrarPadre con el padre de i para encontrar la raíz.
		
*/
// Estructura para representar una arista
struct Arista {
    int origen, destino, peso;
};

// Función para comparar dos aristas por su peso
bool compararAristas(const Arista &a, const Arista &b) {
    return a.peso < b.peso;
}

// Función para encontrar el padre de un nodo en el conjunto
int encontrarPadre(int padre[], int i) {
    if (padre[i] == i)
        return i;
    return encontrarPadre(padre, padre[i]);
}

// Función para unir dos conjuntos
void unirConjuntos(int padre[], int rango[], int x, int y) {
    int xroot = encontrarPadre(padre, x);
    int yroot = encontrarPadre(padre, y);

    if (rango[xroot] < rango[yroot])
        padre[xroot] = yroot;
    else if (rango[xroot] > rango[yroot])
        padre[yroot] = xroot;
    else {
        padre[yroot] = xroot;
        rango[xroot]++;
    }
}

// Función para encontrar el MST usando el algoritmo de Kruskal
void kruskalMST(int** matriz, int n) {
    vector<Arista> aristas;

    // Recorrer la matriz de adyacencia y almacenar las aristas
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matriz[i][j] != -1 && matriz[i][j] != 0) {
                Arista arista;
                arista.origen = i;
                arista.destino = j;
                arista.peso = matriz[i][j];
                aristas.push_back(arista);
            }
        }
    }

    // Ordenar las aristas por peso
    sort(aristas.begin(), aristas.end(), compararAristas);

    // Inicializar el conjunto de padres y rangos
    int *padre = new int[n];
    int *rango = new int[n];
    for (int i = 0; i < n; ++i) {
        padre[i] = i;
        rango[i] = 0;
    }

    vector<Arista> mst;
    for (size_t i = 0; i < aristas.size(); ++i) {
	    Arista arista = aristas[i]; // Acceder al elemento actual usando el índice
	    int x = encontrarPadre(padre, arista.origen);
	    int y = encontrarPadre(padre, arista.destino);
	
	    if (x != y) {
	        mst.push_back(arista);
	        unirConjuntos(padre, rango, x, y);
   		}
	}

    // Imprimir el MST
    color(2);
    cout << endl << "Aristas del MST:" << endl;
    color(15);
    for (Arista arista : mst) {
        cout << "Arista: " << arista.origen << " - " << arista.destino << " con peso: " << arista.peso << endl;
    }

    // Liberar memoria
    delete[] padre;
    delete[] rango;
}
//FIN DE ALGORITMO DE KRUSKAL//////////////////////////////////////////////////////////////////

int main() {
    int n;
    color(10);cout<<"  BIENVENIDO A MI PROGRAMA ESTIMADO :)\n         creacion de grafos "  <<endl;cout<<"========================================="<<endl;
    color(11);cout << "Ingrese la cantidad de nodos: ";color(8);
    cin >> n;color(15);

    // Crear la matriz de adyacencia
    int** matriz = new int*[n];//doble puntero para apuntar tanto a los espacios de la fila de la matriz, como a las columnas que corresponden
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = 0; // Inicializar la matriz con puros 0
        }
    }

    char opcion;
    color(11);cout << "?Desea generar los pesos de forma aleatoria? [";color(2); cout<<"S ";color(11);cout<<"/ ";color(12);cout<<"N";color(11);cout<<"]";color(15);
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        char vaciosOpcion;
        color(11);cout << "?Desea permitir espacios vacios en la matriz? [";color(2); cout<<"S ";color(11);cout<<"/ ";color(12);cout<<"N";color(11);cout<<"]";color(15);
        cin >> vaciosOpcion;
        bool permitirVacios = (vaciosOpcion == 's' || vaciosOpcion == 'S');

        /* GENERAR PESOS VACIOS
        	usamos srand para asignar una semilla de aleatoriedad,
        	y en cada pocision usando doble bucle mandamos a llamar la funcion que genera los aleatorios,
        	el parametro permitirvacios solo sirve para activar la posibilidad de que halla vacios
        	admitidos lo cual hace internamente con un if
        */
        srand(time(0)); // Semilla para n?meros aleatorios
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    matriz[i][j] = 0; // para quitar los lazos hay lazos en un grafo simple
                } else {
                    matriz[i][j] = generarPesoAleatorio(permitirVacios); 
                }
            }
        }
    } else {
        /* INGRESAR PESOS MANUALMENTE
        	todo se desarrolla dentro de un doble bucle para recorrer la matriz,
        	pedimos el peso de cada nodo con la variable input,
        	primero chehcamos si pone "x" que en este caso es para indicar que no hay arista de ese nodo a nodo,
        	luego pasamos y vemos si es un numero con isdigit checando todo el string, para pasarlo depsues a entero con stoi
        */
        color(3);cout << "Ingrese los pesos de la matriz de adyacencia ";color(1);cout<<"(use 'X' para omitir una arista):\n";
        for (int i = 0; i < n; ++i) { //el doble bucle
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    matriz[i][j] = 0; // No hay lazos en un grafo simple
                } else {
                    string input;
                    color(7);cout << "Peso del nodo " << i << " al nodo " << j << " (o 'X' para omitir): ";
                    color(8);cin >> input;color(15);

                    // Verificar si la entrada es 'X' o 'x'
                    if (input == "X" || input == "x") { // Representa un espacio vac?o si detecta que el usuario metio x
                        matriz[i][j] = -1; 
                    } else {
                        // Intentar convertir la entrada a un n?mero
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
                            color(12);cout << "Entrada no v?lida. Se usar? 0 como valor predeterminado.\n";color(15);
                            matriz[i][j] = 0;
                        }//FIN DEL IF VALIDAR NUMERO
                    }//fin del if para leer pesos de nodos
                }
            }//fin del segundo for que recorre la matriz
        }//din del primer for que recorre la matriz
    }//fin del if para llenar manualmente la matriz

    // Imprimir la matriz de adyacencia
    imprimirMatriz(matriz, n);

	 // Encontrar y imprimir el MST usando Kruskal
    kruskalMST(matriz, n);

    // Liberar memoria
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}//FIN DEL MAIN////////////////////////////////////////////////////////////////
