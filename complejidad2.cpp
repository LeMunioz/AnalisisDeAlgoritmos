#include <iostream>
#include <chrono> //para medir el tiempo que le toma hacer instrucciones
#include <iomanip>
#include <vector>
#include <cstdlib> //para el numero random
#include "colores.cpp"
/*
ANGEL EDUARDO MUÑOZ PEREZ
ICOMP CUALTOS 25A
ANALISIS DE ALGORITMOS
Introducción a la complejidad de algoritmos
*/

using namespace std;
using namespace std::chrono;

// Función para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    color(7);
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
    color(15);
}//fin de funcion para imprimir arreglos///////////////////////

/*
    Función para ordenar un arreglo con Bubble Sort
    recorro el arreglo, revisamos cada paso, si el siguiente paso la pocision tiene un valor menor que el anterior, se cambia.
*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); //intercambiar valor si ve que el siguiente es menor
            }
        }
    }
}//Fin de funcin BubbleSort///////////////////////

// Genera un arreglo aleatorio de tamaño n
void generarArregloAleatorio(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000;  // Números entre 0 y 9999
    }
}//fin de funcion generarArregloAleatorio/////////////////////////////

/* 
	FUNCION PARA REALIZAR EL ALGORITMO BURBUJA Y MEDIR CUANTO TIEMPO LE TOMA
		1. Crea un arreglo del tamaño n
		2. La rellena de nuemeros aleatorio invocando la funcion generarArregloAleatorio
		3. usamos el booleano mostrarArreglos el cual se le asigna un valor en main para ver si imprimos el arreglo
		4. usamos high_resolution_clock::now() para marcar el instante en el que iniciamos el proceso ordenar el arrelgo
		5. Invocamos la funcion bubbleSort para ordenar el arreglo
		6. usamos high_resolution_clock::now() para marcar el instante en el que terminamos el proceso ordenar el arreglo
		7. Vemos si volvemos a imprimir el arreglo
		8. metemos el tiempo que tomo en una pila y este valor sera el momento en el que acabo - cuando empezo
*/
vector<double> medirTiempoBubbleSort(int n, bool mostrarArreglos, int repeticiones = 2) {
    vector<double> tiempos;
    int* arr = new int[n]; //puntero para hacer un arreglo de tamaño dinámico

    for (int r = 0; r < repeticiones; ++r) {
        generarArregloAleatorio(arr, n);

        if (mostrarArreglos) {
            cout << "\n--- Repetición " << r + 1 << " ---" << endl;
            cout << "Arreglo desordenado (" << n << " elementos):" << endl;
            imprimirArreglo(arr, n);
        }

        auto inicio = high_resolution_clock::now(); //iniciar el cronometro (guardamos el momento en el que se capturo)
        bubbleSort(arr, n);
        auto fin = high_resolution_clock::now();   //finalizar el cronometro (guardamos el momento en el que se capturo)

        if (mostrarArreglos) {
            cout << "Arreglo ordenado:" << endl;
            imprimirArreglo(arr, n);
        }

        duration<double> duracion = fin - inicio; //hacemos resta de los momentos caputrados para ver cuanto tomo entre iniciar el cronometro y finalizar el cronometro
        tiempos.push_back(duracion.count()); //metemos los valores de tiempos a una lista
        color(3);
        cout << "Tiempo de ordenamiento: " << fixed << setprecision(6) << duracion.count() << " s" << endl;
        color(15);
    }

    delete[] arr;
    return tiempos;
}//fin de la funcion MedirTiempoBurbuja//////////////////////////

int main() {
    char opcion; // variable para escoger si se escribirá los arreglos
    char repetir; // variable para determinar si se repite el programa
    
    do {
        color(3); cout << "      ANGEL EDUARDO MUÑOZ PEREZ" << endl;
        cout << "      Complejidad de Algoritmos" << endl;
        color(1); cout << "=======================================" << endl;
        color(3); cout << "Algoritmo burbuja con vectores de 10, 20, 50, 100, 200, 1000, 5000" << endl;
        color(1); cout << "=======================================" << endl;
        color(15); cout << "¿Deseas ver los vectores antes y después de realizar el algoritmo?" << endl;
        color(2); cout << " [S] "; color(12); cout << "[N] " << endl; color(15);
        cin >> opcion;
        
        srand(time(0));  // Semilla para rand()

        vector<int> lista_n = {10, 20, 50, 100, 200, 1000, 5000};
        bool mostrarArreglos = (opcion == 's' || opcion == 'S'); // Solo mostrar arreglos si se elige 's' o 'S'

        cout << "+-------------------+------------------+" << endl;
        cout << "| n (Tamaño Arreglo)| Tiempo Promedio (s) |" << endl;
        cout << "+-------------------+------------------+" << endl;

        for (int n : lista_n) {
            vector<double> tiempos = medirTiempoBubbleSort(n, mostrarArreglos);
            double promedio = 0;
            for (double t : tiempos) promedio += t;
            promedio /= tiempos.size();

            cout << "| " << setw(17) << n << " | " << setw(16) << fixed << setprecision(6) << promedio << " |" << endl;
        }
        cout << "+-------------------+------------------+" << endl;

        color(15); cout << "¿Deseas realizar otra prueba? (S/N): ";
        cin >> repetir;
    } while (repetir == 'S' || repetir == 's');

    return 0;
}
