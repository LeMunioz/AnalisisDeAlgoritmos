#include <iostream>
#include <chrono>
#include <vector>
#include <cmath> 

using namespace std;
using namespace std::chrono;

// Funci�n con operaciones
void ejecutarInstrucciones(int n) {
    double resultado = 0.0;
    for (int i = 0; i < n; ++i) {
        resultado += sin(i) * cos(i); // Operaci�n matem�tica 
    }
    // Evita que el compilador optimice eliminando el c�lculo
    volatile double evitarOptimizacion = resultado; 
}
//cosorro
int main() {
    int uno =1;
    vector<int> valores_n = {10, 20, 50, 100, 200, 1000, 2000};
    int repeticiones = 2;

    cout << "n\t| Tiempo Ejecuci�n (1)\t| Tiempo Ejecuci�n (2)" << endl;
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
