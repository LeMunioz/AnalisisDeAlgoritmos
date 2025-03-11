#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

struct Edge {
    int target;
    float weight;
};

using Graph = vector<vector<Edge>>;

Graph generateRandomGraph(int numNodes, int numEdges) {
    Graph graph(numNodes);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, numNodes - 1);
    uniform_real_distribution<> weightDis(1.0, 10.0);

    for (int i = 0; i < numEdges; ++i) {
        int from = dis(gen);
        int to = dis(gen);
        float weight = weightDis(gen);
        graph[from].push_back({to, weight});
    }

    return graph;
}
