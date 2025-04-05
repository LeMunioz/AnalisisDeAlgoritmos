#include <iostream>
#include <chrono>
#include <vector>
#include <cmath> 

using namespace std;
using namespace std::chrono;

// Función con operaciones
void ejecutarInstrucciones(int n) {
    double resultado = 0.0;
    for (int i = 0; i < n; ++i) {
        resultado += sin(i) * cos(i); // Operación matemática 
    }
    // Evita que el compilador optimice eliminando el cálculo
    volatile double evitarOptimizacion = resultado; 
}

int main() {
    vector<int> valores_n = {10, 20, 50, 100, 200, 1000, 2000};
    int repeticiones = 2;

    cout << "n\t| Tiempo Ejecución (1)\t| Tiempo Ejecución (2)" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int n : valores_n) {
        cout << n << "\t| ";

        for (int r = 0; r < repeticiones; ++r) {
            auto inicio = high_resolution_clock::now();
            ejecutarInstrucciones(n);
            auto fin = high_resolution_clock::now();

            // Cambiamos a nanosegundos y mostramos
            auto duracion = duration_cast<nanoseconds>(fin - inicio).count();
            cout << duracion << " ns\t| ";
        }
        cout << endl;
    }

    return 0;
}
