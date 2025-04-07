#include <iostream>
#include <chrono> //para medir el tiempo que le toma hacer instrucciones
#include <iomanip>
#include <vector>
#include <cstdlib> //para el numero random

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
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// Función para ordenar un arreglo con Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); //intercambiar valor si ve que el siguiente es menor
            }
        }
    }
}

// Genera un arreglo aleatorio de tamaño n
void generarArregloAleatorio(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000;  // Números entre 0 y 9999
    }
}

// Mide el tiempo de Bubble Sort y muestra arreglos
vector<double> medirTiempoBubbleSort(int n, int repeticiones = 2) {
    vector<double> tiempos;
    int* arr = new int[n]; //puntero para hacer un arreglo de tamaño dinamico

    for (int r = 0; r < repeticiones; ++r) {
        generarArregloAleatorio(arr, n);

        cout << "\n--- Repetición " << r + 1 << " ---" << endl;
        cout << "Arreglo desordenado (" << n << " elementos):" << endl;
        imprimirArreglo(arr, n);

        auto inicio = high_resolution_clock::now(); //iniciar el cronometro (guardamos el momento en el que se capturo)
        bubbleSort(arr, n);
        auto fin = high_resolution_clock::now();   //finalizar el cronometro (guardamos el momento en el que se capturo)

        cout << "Arreglo ordenado:" << endl;
        imprimirArreglo(arr, n);

        duration<double> duracion = fin - inicio; //hacemos resta de los momentos caputrados para ver cuanto tomo entre iniciar el cronometro y finalizar el cronometro
        tiempos.push_back(duracion.count()); //metemos los valores de tiempos a una lista
        cout << "Tiempo de ordenamiento: " << fixed << setprecision(6) << duracion.count() << " s" << endl;
    }

    delete[] arr;
    return tiempos;
}

int main() {
    srand(time(0));  // Semilla para rand()

    vector<int> lista_n = {10, 20, 50, 100, 200, 1000, 5000};

    cout << "+-------------------+------------------+" << endl;
    cout << "| n (Tamaño Arreglo)| Tiempo Promedio (s) |" << endl;
    cout << "+-------------------+------------------+" << endl;

    for (int n : lista_n) {
        vector<double> tiempos = medirTiempoBubbleSort(n);
        double promedio = 0;
        for (double t : tiempos) promedio += t;
        promedio /= tiempos.size();

        cout << "| " << setw(17) << n << " | " << setw(16) << fixed << setprecision(6) << promedio << " |" << endl;
    }
    cout << "+-------------------+------------------+" << endl;

    return 0;
}
