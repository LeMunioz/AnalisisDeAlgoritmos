#include <iostream>
#include <vector>
#include <queue> //para utilizar "pq" que implementa una cola de prioridad.
#include <utility>
#include <climits>
using namespace std;


/*
ANGEL EDUARDO MUÑOZ PEREZ
ANALISIS DE ALGORITMOS
INGENIERIA EN COMPUTACION_ CUALTOS 
8 Marzo 2025
ALGORITMO: Dijkstra
*/

/*
vector<vector<pii>>& graph: El grafo representado como una lista de adyacencia. 
Cada elemento graph[u] es un vector de pares (v, w), donde v es un nodo vecino y w es el peso de la arista.
pq --> 
*/


// Definimos un tipo de dato para representar pares (nodo, peso)
typedef pair<int, int> pii;

//Función para implementar el algoritmo de Dijkstra
	// Inicializamos todas las distancias como infinito
	// Usamos una cola de prioridad (min-heap) para seleccionar el nodo con la menor distancia
	// Insertamos el nodo de inicio con distancia 0
void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX);  
    dist[start] = 0;  			// La distancia al nodo de inicio es 0
    //LA COLA
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});  

    while (!pq.empty()) { 
        int u = pq.top().second;  // Extraemos el nodo con la menor distancia
        int d = pq.top().first;
        pq.pop();

        // ignoro si la siguiente distania es mayor a la que ya tenia
        if (d > dist[u]) continue;

        // Recorremos todos los vecinos del nodo actual
        for (auto& edge : graph[u]) {
            int v = edge.first;  // Nodo vecino
            int w = edge.second;  // Peso de la arista

            // Si la siguiente ruta salio mas corta, la meto en la cola
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }//fin del if
        }//fin del for
    }//fin del while
}

int main() {
    int n, m;  // n = número de nodos, m = número de aristas
    cout << "Ingrese el número de nodos y aristas: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);  // Lista de adyacencia para representar el grafo

    cout << "Ingrese las aristas (u, v, w) donde u y v son nodos y w es el peso: " << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});  // Grafo no dirigido
        graph[v].push_back({u, w});  // Si es dirigido, elimina esta línea
    }//fin del for

    int start;
    cout << "Ingrese el nodo de inicio: ";
    cin >> start;

    vector<int> dist(n);
    dijkstra(start, graph, dist);

    cout << "Distancias desde el nodo " << start << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Nodo " << i << ": " << dist[i] << endl;
    }//fin del for

    return 0;
}
