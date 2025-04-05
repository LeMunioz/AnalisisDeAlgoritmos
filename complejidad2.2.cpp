#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
ANGEL EDUARDO MUÑOZ PEREZ
INGENIERIA EN COMPUTACION_ CUALTOS 25A
ANALISIS DE ALGORITMOS Prof. Hector
ANALIS DE COMLEJIDAD
*/

// Función que ejecuta 'n' instrucciones (incrementos)
void ejecutarInstrucciones(int n) {
    int contador = 0;
    for (int i = 0; i < n; ++i) {
        contador++;  // Instrucción simple
    }
}

int main() {
    vector<int> valores_n = {10, 20, 50, 100, 200, 1000, 2000};
    int repeticiones = 2;  // Ejecutar cada n al menos 2 veces

    // Encabezado de la tabla
    cout << "n\t| Tiempo Ejecución (1)\t| Tiempo Ejecución (2)" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int n : valores_n) {
        cout << n << "\t| ";

        for (int r = 0; r < repeticiones; ++r) {
            // Iniciar medición de tiempo
            auto inicio = high_resolution_clock::now();

            // Ejecutar las 'n' instrucciones
            ejecutarInstrucciones(n);

            // Finalizar medición
            auto fin = high_resolution_clock::now();

            // Calcular duración en microsegundos (o nanosegundos)
            auto duracion = duration_cast<microseconds>(fin - inicio).count();

            cout << duracion << " us\t\t| ";
        }
        cout << endl;
    }

    return 0;
}
